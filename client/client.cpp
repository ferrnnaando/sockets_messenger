#include <iostream>
#include <string>
#include <WinSock2.h> // Winsock functions, structures, and definitions
#include <WS2tcpip.h> // definitions introduced in the WinSock 2 Protocol-Specific Annex document for TCP/IP that includes newer functions and structures used to retrieve IP addresses.
#include <iphlpapi.h>
#include <cstdio>

#include "error_handling/error_handling.h"
#include "SocketConnexionHandler/SocketConnexionHandler.h"
#pragma comment(lib, "Ws2_32.lib")

class resolveServerAddress {
    //https://es.wikipedia.org/wiki/Anexo:Puertos_de_red
    public:
        resolveServerAddress();
        ~resolveServerAddress();

        typedef struct IRC {
            const PCSTR SERVER_PORT    = "6667";
            const PCSTR SERVER_ADDRESS = "127.0.0.1";
            const UINT  BUFFERSIZE   = 1024;
        };

        struct addrinfo* result = nullptr, *ptr = nullptr, hints;
};

resolveServerAddress::resolveServerAddress() {
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family   = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
}

resolveServerAddress::~resolveServerAddress() {};

int __cdecl main() {
    UINT CON_RSLT, RESOLVE_SERVER_CONNEX, resolveServerConnection;
    SOCKET ConnectSocket = INVALID_SOCKET;

    ERROR_HANDLING::MB_BADSTART MB_BADSTARTUP;
    ERROR_HANDLING::MB_BADCONNEXION MB_BADCONNEX;
    WSADATA wsaData;
    WORD    wVersionRequested = MAKEWORD(2, 2);
    CON_RSLT = WSAStartup(wVersionRequested, &wsaData);

    resolveServerAddress serverSocket;
    resolveServerAddress::IRC serverConnexion;
    RESOLVE_SERVER_CONNEX = getaddrinfo(serverConnexion.SERVER_ADDRESS, serverConnexion.SERVER_PORT, &serverSocket.hints, &serverSocket.result);

    resolveServerConnection = SocketConnexionHandler(CON_RSLT, RESOLVE_SERVER_CONNEX, MB_BADSTARTUP, MB_BADCONNEX);
    if (resolveServerConnection != 0) return resolveServerConnection;

    ConnectSocket = socket(serverSocket.hints.ai_family, serverSocket.hints.ai_socktype, serverSocket.hints.ai_protocol);

    //hibite, lobite, ushort,short, u_short, u_long,

    WSACleanup();
    std::system("pause");
	return 0;
}