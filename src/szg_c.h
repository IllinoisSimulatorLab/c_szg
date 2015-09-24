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

    int EXPORT_API szgClient_connect( arSZGClient* cli, char* forcedName );

    void EXPORT_API szgClient_disconnect( arSZGClient* cli );
            
    void EXPORT_API szgClient_delete( arSZGClient* cli );
}

#endif
