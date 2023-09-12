#include "SocketConnexionHandler.h"

int SocketConnexionHandler(UINT& CON_RSLT,
                           SOCKET& ConnectSocket,
                           UINT& RESOLVE_SERVER_CONNEX, 
                           ERROR_HANDLING::MB_BADSTART* MB_BADSTARTUP, 
                           ERROR_HANDLING::MB_BADCONNEXION* MB_BADADDR
                          ) {
    switch (CON_RSLT) {
    case 0:
        break;

    default:
        MessageBox(MB_BADSTARTUP->hWnd, MB_BADSTARTUP->CONTENT, MB_BADSTARTUP->TITLE, MB_BADSTARTUP->type);
        WSACleanup();
        return -1;
    }

    switch (RESOLVE_SERVER_CONNEX) {
    case 0:
        break;

    default:
        MessageBox(MB_BADADDR->hWnd, MB_BADADDR->CONTENT, MB_BADADDR->TITLE, MB_BADADDR->type);
        WSACleanup();
        return -1;
    }

    switch (ConnectSocket) {
        case INVALID_SOCKET:
            MessageBox(MB_BADADDR->hWnd, MB_BADADDR->CONTENT, MB_BADADDR->TITLE, MB_BADADDR->type);
            WSACleanup();
            return -1;

        default:
            break;
    }

    return 0;
}