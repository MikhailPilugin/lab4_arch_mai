#ifndef CONFERENCE_H
#define CONFERENCE_H

#include <string>
#include <vector>
#include "Poco/JSON/Object.h"
#include <optional>
#include "report.h"

namespace database
{
    class Conference{
        private:
            long _id;
            long _report_id;
            std::string _user_login;

        static std::vector<Conference> read_all(const std::string &where);

        public:

            static Conference fromJSON(const std::string & str);

            long getId() const;
            const long &getReportId() const;
            const std::string &getUser() const;

            long& id();
            long &report();
            std::string &user();

            static void init();
            static std::vector<Conference> readAll();
            static std::vector<Report> readAllFor(const std::string &login);
            void saveToMySQL();

            Poco::JSON::Object::Ptr toJSON(bool exclude_id) const;

    };
}

#endif