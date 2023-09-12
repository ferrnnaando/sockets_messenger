#include "SocketConnexionHandler.h"

SocketConnexionHandler::SocketConnexionHandler(UINT& CON_RESULT, SOCKET& ConnectSocketHandler, UINT& RESOLVE_SERVER_CONNEXION) {
    CON_RSLT = &CON_RESULT;
    ConnectSocket = &ConnectSocketHandler;
    RESOLVE_SERVER_CONNEX = &RESOLVE_SERVER_CONNEXION;
}

int SocketConnexionHandler::connResolver() {
    switch (*CON_RSLT) {
    case 0:
        break;

    default:
        MessageBox(MB_BADSTARTUP->hWnd, MB_BADSTARTUP->CONTENT, MB_BADSTARTUP->TITLE, MB_BADSTARTUP->type);
        return -1;
    }

    switch (*RESOLVE_SERVER_CONNEX) {
    case 0:
        break;

    default:
        MessageBox(MB_BADADDR->hWnd, MB_BADADDR->CONTENT, MB_BADADDR->TITLE, MB_BADADDR->type);
        return -1;
    }

    switch (*ConnectSocket) {
        case INVALID_SOCKET:
            MessageBox(MB_BADSOCKET->hWnd, MB_BADSOCKET->CONTENT, MB_BADSOCKET->TITLE, MB_BADSOCKET->type);
            return -1;

        default:
            break;
    }

    return 0;
}