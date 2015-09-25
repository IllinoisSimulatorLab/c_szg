#ifndef SZG_CONFIG_H
#define SZG_CONFIG_H

#include "arPhleetConfig.h"

extern "C" {
    // arPhleetConfig
    //
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

}    

#endif

