#pragma once
#include <iostream>
#include <WinSock2.h> // Winsock functions, structures, and definitions
#include <WS2tcpip.h> // definitions introduced in the WinSock 2 Protocol-Specific Annex document for TCP/IP that includes newer functions and structures used to retrieve IP addresses.
#include <iphlpapi.h>
#include <cstdio>

class ERROR_HANDLING {
    public:
        typedef struct MB_BADSTART {
            const HWND   hWnd    = nullptr;
            const LPCSTR TITLE   = "Internal error.";
            const LPCSTR CONTENT = "There was an error trying to match the requirements, please reinstall your system.";
            const UINT   type    = MB_OK | MB_ICONERROR;
        };

        typedef struct MB_BADCONNEXION {
            const HWND   hWnd = nullptr;
            const LPCSTR TITLE = "Connexion error.";
            const LPCSTR CONTENT = "Connection refused: Uknown host."; //this should never happen since the server-side host is our own PC
            const UINT   type = MB_OK | MB_ICONERROR;
        };
};