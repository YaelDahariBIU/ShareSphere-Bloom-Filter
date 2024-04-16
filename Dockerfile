FROM gcc:latest

WORKDIR /usr/src/facebook-like

COPY ./src/ .

RUN g++ -o facebook-like ./BFApp/* ./BloomFilter/* ./Command/* ./Hash/* ./tcpServer.cpp
EXPOSE 5555
CMD ["./facebook-like"]