#include "conference.h"
#include "database.h"
#include "report.h"
#include "../config/config.h"

#include <Poco/Data/MySQL/Connector.h>
#include <Poco/Data/MySQL/MySQLException.h>
#include <Poco/Data/SessionFactory.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>

#include <sstream>
#include <exception>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

namespace database
{
    void Conference::init()
    {
        try
        {
            Poco::Data::Session session = database::Database::get().create_session();
            Statement create_stmt(session);
            create_stmt << "CREATE TABLE IF NOT EXISTS `Conference` (`id` INT NOT NULL AUTO_INCREMENT,"
                        << "`reportId` INT NOT NULL,"
                        << "`userLogin` VARCHAR(256) NOT NULL,"
                        << "PRIMARY KEY (`id`),"
                        << "FOREIGN KEY (`reportId`) REFERENCES Report (`id`),"
                        << "KEY `ul` (`userLogin`));",
                now;
        }
        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.what() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.what() << std::endl;
            throw;
        }
    }

    std::vector<Report> Conference::readAllFor(const std::string &login)
    {
        try
        {
            Poco::Data::Session session = database::Database::get().create_session();
            Statement select(session);
            std::vector<Report> result;
            Report a;

            std::string sql = "SELECT id, name, type, description, author FROM report WHERE id IN (SELECT reportId FROM conference WHERE userLogin=\"" + login + "\")";
            std::cout << "SQL Request: " << sql << std::endl;
            select << sql,
                into(a.id()),
                into(a.name()),
                into(a.type()),
                into(a.description()),
                into(a.author()),
                range(0, 1);

            while (!select.done())
            {
                if (select.execute())
                    result.push_back(a);
            }
            return result;
        }
        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.what() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.what() << std::endl << e.displayText() << std::endl;
            throw;
        }
    }

    std::vector<Conference> Conference::readAll()
    {
        try
        {
            Poco::Data::Session session = database::Database::get().create_session();
            Statement select(session);
            std::vector<Conference> result;
            Conference a;

            std::string sql = "SELECT reportId, userLogin FROM Conference";
            std::cout << "SQL Request: " << sql << std::endl;
            select << sql,
                into(a._report_id),
                into(a._user_login),
                range(0, 1);

            while (!select.done())
            {
                if (select.execute())
                    result.push_back(a);
            }
            return result;
        }
        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.what() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.what() << std::endl << e.displayText() << std::endl;
            throw;
        }
    }

    void Conference::saveToMySQL()
    {
        try
        {
            Poco::Data::Session session = database::Database::get().create_session();
            Poco::Data::Statement insert(session);

            insert << "INSERT INTO Conference (reportId, userLogin) VALUES(?, ?)",
                use(_report_id),
                use(_user_login);

            insert.execute();

            Poco::Data::Statement select(session);
            select << "SELECT LAST_INSERT_ID()",
                into(_id),
                range(0, 1); //  iterate over result set one row at a time

            if (!select.done())
            {
                select.execute();
            }
            std::cout << "Inserted conference id: " << _id << std::endl;
        }
        catch (Poco::Data::MySQL::ConnectionException &e)
        {
            std::cout << "connection:" << e.what() << std::endl;
            throw;
        }
        catch (Poco::Data::MySQL::StatementException &e)
        {

            std::cout << "statement:" << e.what() << std::endl;
            throw;
        }
    }

    Poco::JSON::Object::Ptr Conference::toJSON(bool exclude_id=false) const
    {
        Poco::JSON::Object::Ptr root = new Poco::JSON::Object();

        if (!exclude_id)
            root->set("id", _id);
        root->set("reportId", _report_id);
        root->set("userLogin", _user_login);

        return root;
    }

    long Conference::getId() const { return _id; }
    const long &Conference::getReportId() const { return _report_id; }
    const std::string &Conference::getUser() const { return _user_login; }

    long& Conference::id() { return _id; }
    long &Conference::report() { return _report_id; }
    std::string &Conference::user() { return _user_login; }
}