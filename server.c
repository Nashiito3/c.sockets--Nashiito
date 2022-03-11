#include <studio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
int main()
{
    int server_socket; //sckt
    int client_socket; //accetp
    struct sockaddr_in server_addr;
    char buffer[1024] = "connected";
    char recv_buffer[1024];

    server_socket = socket(AF_INET, SOCK_STREAM, 0); // ipv4, tcp

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //ip (local rn)

    bind(server_socket, (struct server_addr*) &server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    client_socket = accept(server_socket, NULL, NULL);
    printf("connected as сыпь(rash) ");
    send(client_socket, buffer, sizeof(buffer), 0);
    recv(client_socket, recv_buffer, sizeof(recv_buffer), 0);
    printf("sent", recv_buffer);
    close(server_socket);
    return 0;

}
