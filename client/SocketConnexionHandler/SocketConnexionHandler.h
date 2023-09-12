#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

class ERROR_HANDLING {
public:
    typedef struct MB_BADSTART {
        const HWND   hWnd = nullptr;
        const LPCSTR TITLE = "Internal error.";
        const LPCSTR CONTENT = "There was an error trying to match the requirements, please reinstall your system.";
        const UINT   type = MB_OK | MB_ICONERROR;
    };

    typedef struct MB_BADCONNEXION {
        const HWND   hWnd = nullptr;
        const LPCSTR TITLE = "Connexion error.";
        const LPCSTR CONTENT = "Connection refused: Uknown host."; //this should never happen since the server-side host is our own PC
        const UINT   type = MB_OK | MB_ICONERROR;
    };
};

int SocketConnexionHandler(UINT& CON_RSLT, SOCKET& ConnectSocket, UINT& RESOLVE_SERVER_CONNEX, ERROR_HANDLING::MB_BADSTART* MB_BADSTARTUP, ERROR_HANDLING::MB_BADCONNEXION* MB_BADADDR);