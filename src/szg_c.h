#ifndef SZG_C_H
#define SZG_C_H

#include "arSZGClient.h"

#ifdef AR_USE_WIN_32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif


extern "C" {
    arSZGClient* EXPORT_API szgClient();

    int EXPORT_API connect_szgClient( arSZGClient* cli, char* forcedName );

    void EXPORT_API disconnect_szgClient( arSZGClient* cli );
            
    void EXPORT_API delete_szgClient( arSZGClient* cli );
}

#endif
