#include "szg_c.h"

#include <string>

#define PRINT_ERROR(x)


arPhleetConfig* szgConfig() {
    return new arPhleetConfig();
}


void szgConfig_delete( arPhleetConfig* cfg ) {
    if (cfg == NULL) {
        PRINT_ERROR( "szgConfig_delete() passed NULL pointer" );
        return;
    }
    delete cfg;
}


bool szgConfig_read( arPhleetConfig* cfg ) {
    return cfg->read();
}

bool szgConfig_write( arPhleetConfig* cfg ) {
    return cfg->write();
}

bool szgConfig_readLogin( arPhleetConfig* cfg ) {
    return cfg->readLogin();
}

bool szgConfig_writeLogin( arPhleetConfig* cfg ) {
    return cfg->writeLogin();
}


char* szgConfig_getComputerName( arPhleetConfig* cfg ) {
    std::string val = cfg->getComputerName();
    return _stringToBuf( val );
}


// get login info
char* szgConfig_getUserName( arPhleetConfig* cfg ) {
    std::string val = cfg->getUserName();
    return _stringToBuf( val );
}

char* szgConfig_getServerName( arPhleetConfig* cfg ) {
    std::string val = cfg->getServerName();
    return _stringToBuf( val );
}

char* szgConfig_getServerIP( arPhleetConfig* cfg ) {
    std::string val = cfg->getServerIP();
    return _stringToBuf( val );
}

int szgConfig_getServerPort( arPhleetConfig* cfg ) {
    return cfg->getServerPort();
}



