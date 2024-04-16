#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include "BFApp/Runner.h"

using namespace std;
bool isInit = false;

// Struct to hold arguments for handle_client function
struct ClientArgs {
    int client_sock;
    Runner runner;
};

void *handle_client(void *arg)
{
    ClientArgs *args = (ClientArgs *)arg;
    int client_sock = args->client_sock;
    char answer[6] = {};
    strcpy(answer, "true");

    char buffer[4096];
    int read_bytes;

    // Continue to receive messages until the client sends the "close" message
    while ((read_bytes = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
        strcpy(answer, "true");
        buffer[read_bytes] = '\0'; // Null-terminate the received data
        cout << "Received message from client: " << buffer << endl;

        // Check if the received message is the "close" message
        if (strcmp(buffer, "close") == 0)
        {
            cout << "Closing connection with client." << endl;
            break; // Exit the loop and close the connection
        }

        // execute and return the answer to the client
        if (isInit) {
            if (args->runner.execute(buffer)) {
                strcpy(answer, "false");
                cout << "Found bad!!!!!" << endl;
            }
        }
        else {
            args->runner.init(buffer);
            isInit = true;
        }

        int sent_bytes = send(client_sock, (void *)answer, sizeof(answer), 0);
        if (sent_bytes < 0)
        {
            perror("error sending to client");
            break;
        }
    }

    close(client_sock);
    delete args;
    return NULL;
}


int main()
{
    const int server_port = 5555;
    const char * server_ip = "127.0.0.1";
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(server_ip);
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
        close(sock);
        return 1;
    }

    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
        close(sock);
        return 1;
    }

    Runner runner = Runner();

    while (true)
    {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int *client_sock = new int;
        *client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (*client_sock < 0)
        {
            perror("error accepting client");
            delete client_sock;
            continue;
        }

        // Create arguments struct
        auto *args = new ClientArgs;
        args->client_sock = *client_sock;
        args->runner = runner;

        pthread_t tid;

        if (pthread_create(&tid, NULL, handle_client, (void *)args) != 0)
        {
            perror("error creating thread");
            delete client_sock;
            continue;
        }

        // Detach the thread to clean up resources automatically
        pthread_detach(tid);
    }
    close(sock);
    return 0;
}
