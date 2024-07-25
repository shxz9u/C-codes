#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000

int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *exit_message = "exit";
    char *connection_message = "Server: Connection established";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    send(new_socket, connection_message, strlen(connection_message), 0);

    while (1)
    {
        printf("Waiting...\n");
        valread = read(new_socket, buffer, 1024);
        buffer[valread] = '\0';
        printf("Client: %s\n", buffer);

        if (strncmp(buffer, exit_message, strlen(exit_message)) == 0)
        {
            printf("Exiting...\n");
            break;
        }

        printf("Server: ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        send(new_socket, buffer, strlen(buffer), 0);

        if (strncmp(buffer, exit_message, strlen(exit_message)) == 0)
        {
            printf("Exiting...\n");
            break;
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
