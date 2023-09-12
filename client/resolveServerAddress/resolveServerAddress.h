#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

class resolveServerAddress {
    public:
        resolveServerAddress();
        ~resolveServerAddress() {};

        struct IRC {
            const PCSTR SERVER_PORT = "6667";
            const PCSTR SERVER_ADDRESS = "127.0.0.1";
            const UINT  BUFFERSIZE = 1024;
        };

        struct addrinfo* result = nullptr, *ptr = nullptr, hints;
};

//https://es.wikipedia.org/wiki/Anexo:Puertos_de_red