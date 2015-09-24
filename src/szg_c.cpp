#include "szg_c.h"

#include <string>

#define PRINT_ERROR(x)


char* _stringToBuf( std::string& str ) {
    char* buf = (char*)malloc( str.size()+1 );
    memcpy( buf, str.c_str(), str.size()+1 );
    return buf;
}


void cfree( void* ptr ) {
    free( ptr );
}


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



std::string _bufString;

char* argvG[] = {"unity"};
int argcG = 1;


arSZGClient* szgClient() {
    return new arSZGClient();
}


int szgClient_connect( arSZGClient* cli, char* forcedName ) {
    int retVal = -1;
    int argc = argcG;
    char** argvPtr = new char*[argc];
    for (int i=0; i<argc; ++i) {
        argvPtr[i] = new char[strlen(argvG[i])];
    }
    if (cli->init( argc, argvPtr, forcedName )) {
        retVal = argc;
    }
    for (int i=0; i<argc; ++i) {
        delete[] argvPtr[i];
    }
    delete[] argvPtr;
    return retVal;
}


void szgClient_disconnect( arSZGClient* cli ) {
    cli->closeConnection();
}
        

void szgClient_delete( arSZGClient* cli ) {
    if (cli == NULL) {
        return;
    }
    delete cli;
}


