FROM gcc:latest

WORKDIR /usr/src/facebook-like

COPY ./src/ .

RUN g++ -o facebook-like ./main.cpp

CMD ["./facebook-like"]