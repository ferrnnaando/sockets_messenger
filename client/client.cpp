#include <string>
#include <WinSock2.h> // Winsock functions, structures, and definitions
#include <WS2tcpip.h> // definitions introduced in the WinSock 2 Protocol-Specific Annex document for TCP/IP that includes newer functions and structures used to retrieve IP addresses.
#include <iphlpapi.h>
#include <cstdio>
#pragma comment(lib, "Ws2_32.lib")

#include "resolveServerAddress/resolveServerAddress.h"
#include "SocketConnexionHandler/SocketConnexionHandler.h"

int __cdecl main(SOCKET()) {
    int resolveServerConnection;
    UINT CON_RSLT, RESOLVE_SERVER_CONNEX;
    SOCKET ConnectSocket = INVALID_SOCKET;

    WSADATA wsaData;
    WORD    wVersionRequested = MAKEWORD(2, 2);
    CON_RSLT = WSAStartup(wVersionRequested, &wsaData);

    resolveServerAddress serverSocket;
    resolveServerAddress::IRC serverConnexion;

    RESOLVE_SERVER_CONNEX = getaddrinfo(serverConnexion.SERVER_ADDRESS, serverConnexion.SERVER_PORT, &serverSocket.hints, &serverSocket.result);
    ConnectSocket = socket(serverSocket.hints.ai_family, serverSocket.hints.ai_socktype, serverSocket.hints.ai_protocol);

    SocketConnexionHandler connHandler(CON_RSLT, ConnectSocket, RESOLVE_SERVER_CONNEX);
    resolveServerConnection = connHandler.connResolver();
    switch(resolveServerConnection) {
        case 0:
            break;

        default:
            WSACleanup();
            return resolveServerConnection;
    }

    //hibite, lobite, ushort,short, u_short, u_long,

    WSACleanup();
    std::system("pause");
	return 0;
}