#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

class ERROR_HANDLING {
public:
    ERROR_HANDLING() {};
    ~ERROR_HANDLING() {}; //why typedef are being ignored
    struct MB_BADSTART {
        const HWND   hWnd = nullptr;
        const LPCSTR TITLE = "Internal error.";
        const LPCSTR CONTENT = "There was an error trying to match the requirements, please reinstall your system.";
        const UINT   type = MB_OK | MB_ICONERROR;
    };

    struct MB_BADADDR {
        const HWND   hWnd = nullptr;
        const LPCSTR TITLE = "Connexion refusing.";
        const LPCSTR CONTENT = "Connection refused: Uknown host."; //this should never happen since the server-side host is our own PC
        const UINT   type = MB_OK | MB_ICONERROR;
    };

    struct MB_BADSOCKET {
        const HWND   hWnd = nullptr;
        const LPCSTR TITLE = "Connexion error.";
        const LPCSTR CONTENT = "Connection refused: Impossible to connect. Check your router."; //this should never happen since the server-side host is our own PC
        const UINT   type = MB_OK | MB_ICONERROR;
    };

    protected:
        ERROR_HANDLING::MB_BADSTART ptr_MBBADSTARTUP;
        ERROR_HANDLING::MB_BADADDR ptr_MBBADADDR;
        ERROR_HANDLING::MB_BADSOCKET ptr_MBBADSOCKET;

        ERROR_HANDLING::MB_BADSTART* MB_BADSTARTUP = &ptr_MBBADSTARTUP;;
        ERROR_HANDLING::MB_BADADDR* MB_BADADDR = &ptr_MBBADADDR;
        ERROR_HANDLING::MB_BADSOCKET* MB_BADSOCKET = &ptr_MBBADSOCKET;
};

class SocketConnexionHandler : ERROR_HANDLING {
    public:
        SocketConnexionHandler(UINT& CON_RESULT, SOCKET& ConnectSocketHandler, UINT& RESOLVE_SERVER_CONNEXION);
        ~SocketConnexionHandler() {};

        int connResolver();
    private:
        UINT* CON_RSLT;
        SOCKET* ConnectSocket;
        UINT* RESOLVE_SERVER_CONNEX;
};