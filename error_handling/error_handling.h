#pragma once
#include <iostream>
#include <WinSock2.h> // Winsock functions, structures, and definitions
#include <WS2tcpip.h> // definitions introduced in the WinSock 2 Protocol-Specific Annex document for TCP/IP that includes newer functions and structures used to retrieve IP addresses.
#include <iphlpapi.h>
#include <cstdio>

class ERROR_HANDLING {
public:
    typedef struct MB_BADCON;
};