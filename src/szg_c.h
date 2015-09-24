#ifndef SZG_C_H
#define SZG_C_H

#include "arSZGClient.h"

#ifdef AR_USE_WIN_32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif


extern "C" {

    void EXPORT_API cfree( void* ptr );
    
    arPhleetConfig* EXPORT_API szgConfig();

    void EXPORT_API szgConfig_delete( arPhleetConfig* cfg );

    bool EXPORT_API szgConfig_read( arPhleetConfig* cfg );
    bool EXPORT_API szgConfig_write( arPhleetConfig* cfg );

    bool EXPORT_API szgConfig_readLogin( arPhleetConfig* cfg );
    bool EXPORT_API szgConfig_writeLogin( arPhleetConfig* cfg );

    // computer name, as parsed from the config file
    // user responsible for free()-ing returned buffer
    char* EXPORT_API szgConfig_getComputerName( arPhleetConfig* cfg );
    
    // get login info
    char* EXPORT_API szgConfig_getUserName( arPhleetConfig* cfg );
    char* EXPORT_API szgConfig_getServerName( arPhleetConfig* cfg );
    char* EXPORT_API szgConfig_getServerIP( arPhleetConfig* cfg );
    int EXPORT_API szgConfig_getServerPort( arPhleetConfig* cfg );

//    bool determineFileLocations( string& configLocation, string& loginFileLocation );

    
    arSZGClient* EXPORT_API szgClient();

    int EXPORT_API szgClient_connect( arSZGClient* cli, char* forcedName );

    void EXPORT_API szgClient_disconnect( arSZGClient* cli );
            
    void EXPORT_API szgClient_delete( arSZGClient* cli );
}

#endif
