#include <WinSock2.h>
#include <WS2rcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    SOCKET client_socket;
    WSADATA wasstructure;
    int result;
    struct sockaddr_in client_addr;
    char sendData[1024] = "connected";
    char recvData[1024];


    result = WSAStartup(MAKEWORD(2, 2), &wsastructure); 
    if (result != 0)
    {
        printf("failed");
        return 1;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    client_addr.sin_family = AF_INET;
    cleint_addr.sin.port = htons(8080); //port
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //ip

    connect(client_socket, (SOCKADDR*) &client_addr, sizeof(client_addr));

    recv(client_socket, recvData, sizeof(recvData), 0);
    printf("server", recvData);
    send(client_socket, sendData, sizeof(sendData),0);
    closesocket(client_socket);
    WSACleanup();
    return 0;


}