FROM ubuntu
ENV TZ=Europe/Moscow
RUN apt-get clean && apt-get update -y 
RUN DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC apt-get -y install tzdata git sudo build-essential autoconf libtool libssl-dev zlib1g-dev librdkafka-dev pkg-config cmake gcc git g++ mysql-client libmysqlclient-dev libboost-all-dev libssl-dev && apt-get clean
RUN git clone -b poco-1.12.4-release https://github.com/pocoproject/poco.git && cd poco && mkdir cmake-build && cd cmake-build && cmake .. && make && sudo make install && cd .. && cd ..
RUN git clone https://github.com/tdv/redis-cpp.git && cd redis-cpp && mkdir build && cd build && cmake .. && make && sudo make install && cd .. && cd .. 

# -- Remote --
RUN git clone https://github.com/MikhailPilugin/lab4_arch_mai.git services
RUN sudo ldconfig
RUN cd services && mkdir build && cd build && cmake  .. && make
ENTRYPOINT [ "services/build/account" ]

# -- Local --
#COPY ./build/ build/
#RUN sudo ldconfig
#ENTRYPOINT [ "build/account" ]