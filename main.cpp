#include <iostream>
#include <WinSock2.h> // Winsock functions, structures, and definitions
#include <WS2tcpip.h> // definitions introduced in the WinSock 2 Protocol-Specific Annex document for TCP/IP that includes newer functions and structures used to retrieve IP addresses.
#include <iphlpapi.h>
#include <cstdio>

#include "error_handling/error_handling.h"
#pragma comment(lib, "Ws2_32.lib")

class ERROR_HANDLING {
    public:
        typedef struct MB_BADCON {
            const HWND   hWnd    = NULL;
            const LPCSTR TITLE   = "Connectivity troubles.";
            const LPCSTR CONTENT = "There was an error trying to connect to the application, please check your internet connection.";
            const UINT   type    = MB_OK | MB_ICONERROR;
        };
};

class ARCH_CONN {
    //https://es.wikipedia.org/wiki/Anexo:Puertos_de_red
    private:
        typedef struct IRC {
            const UINT PORT         = 6667;
            const UINT BUFFERSIZE_1 = 1024;
            const UINT BUFFERSIZ_2  = 4096;
        };

        struct addrinfo* result = NULL,
            * ptr = NULL,
            hints;

    public:
        ARCH_CONN();
        ~ARCH_CONN();
};

ARCH_CONN::ARCH_CONN() {
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family   = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
}

ARCH_CONN::~ARCH_CONN() {};

int __cdecl main() {
    ERROR_HANDLING::MB_BADCON MB_BADCON;

    WSADATA wsaData;
    WORD    wVersionRequested = MAKEWORD(2, 2);
    UINT    CON_RSLT          = WSAStartup(wVersionRequested, &wsaData);

    switch(CON_RSLT) {
        case 0:
            break;

        default:
            MessageBox(MB_BADCON.hWnd, MB_BADCON.CONTENT, MB_BADCON.TITLE, MB_BADCON.type);
            WSACleanup();
            break;
    }
    

    //hibite, lobite

    WSACleanup();
    std::system("pause");
	return 0;
}

//Sockets are a abstraction thar represents an endpoint for receiving or sending data over a network. Sockets are a fundamental concept in the network programming and they come into two types.

//Stream Sockets (TCP)
// - Stream Sockets uses the TCP (Transmission Control Protocol) for precise communication. Provides a reliable connection, orientered and ordered stream of data transmission
// - Are often used to communicate precisely where the data ingregity are priority and crucial like file transfer.

//Datagram Sockets (UDP)
// - Datagram sockets uses the UDP (User Datagram Protocol) for communication. This socket type is more unreliable and provides a unordered connection mechanism.
// - UDP are suitable for applications where exists a lot of connections and have to be fast like chat messaing or multiplayer games.