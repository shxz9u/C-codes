#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    char *exit_message = "exit";

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    valread = read(sock, buffer, 1024);
    buffer[valread] = '\0';
    printf("%s\n", buffer);

    while (1)
    {
        printf("Client: ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        send(sock, buffer, strlen(buffer), 0);

        if (strncmp(buffer, exit_message, strlen(exit_message)) == 0)
        {
            printf("Exiting...\n");
            break;
        }

        printf("Waiting...\n");
        valread = read(sock, buffer, 1024);
        buffer[valread] = '\0';
        printf("Server: %s\n", buffer);

        if (strncmp(buffer, exit_message, strlen(exit_message)) == 0)
        {
            printf("Exiting...\n");
            break;
        }
    }

    close(sock);
    return 0;
}
