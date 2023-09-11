#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iphlpapi.h>

#include "../error_handling/error_handling.h"

constexpr int SocketConnexionHandler(UINT& CON_RSLT,
                           UINT& RESOLVE_SERVER_CONNEX,
                           ERROR_HANDLING::MB_BADSTART& MB_BADSTARTUP,
                           ERROR_HANDLING::MB_BADCONNEXION& MB_BADCONNEX
                         );