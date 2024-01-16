FROM gcc:latest

WORKDIR /usr/src/facebook-like

COPY ./src/ .

RUN g++ -o facebook-like ./bloom_filter.cpp

CMD ["./facebook-like"]