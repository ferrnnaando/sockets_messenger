#include "SocketConnexionHandler.h"

constexpr int SocketConnexionHandler(UINT& CON_RSLT, 
                           UINT& RESOLVE_SERVER_CONNEX, 
                           ERROR_HANDLING::MB_BADSTART& MB_BADSTARTUP, 
                           ERROR_HANDLING::MB_BADCONNEXION& MB_BADCONNEX
                          ) {
    switch (CON_RSLT) {
    case 0:
        break;

    default:
        MessageBox(MB_BADSTARTUP.hWnd, MB_BADSTARTUP.CONTENT, MB_BADSTARTUP.TITLE, MB_BADSTARTUP.type);
        WSACleanup();
        return -1;
    }

    switch (RESOLVE_SERVER_CONNEX) {
    case 0:
        break;

    default:
        MessageBox(MB_BADCONNEX.hWnd, MB_BADCONNEX.CONTENT, MB_BADCONNEX.TITLE, MB_BADCONNEX.type);
        WSACleanup();
        return -1;
    }

    return 0;
}