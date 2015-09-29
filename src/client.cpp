#include "szg_c.h"

#include <string>

#define PRINT_ERROR(x)


std::string _bufString;

char* argvG[] = {"szg_c.exe"};
int argcG = 1;


arSZGClient* szgClient() {
    return new arSZGClient();
}


void szgClient_delete( arSZGClient* cli ) {
    if (cli == NULL) {
        return;
    }
    delete cli;
}


int szgClient_connect( arSZGClient* cli, char* forcedName ) {
    int retVal = -1;
    int argc = argcG;
    char** argvPtr = new char*[argc];
    std::string frcName( forcedName );
    for (int i=0; i<argc; ++i) {
        int len = strlen(argvG[i])+1;
        argvPtr[i] = new char[len];
        memcpy( argvPtr[i], argvG[i], len );
    }
    if (cli->init( argc, argvPtr, frcName )) {
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
        

void szgClient_simpleHandshaking( arSZGClient* cli, bool state ) {
    cli->simpleHandshaking( state );
}


int szgClient_failStandalone( arSZGClient* cli, bool fInited ) {
    return cli->failStandalone( fInited );
}

bool szgClient_sendInitResponse( arSZGClient* cli, bool ok ) {
    return cli->sendInitResponse( ok );
}

bool szgClient_sendStartResponse( arSZGClient* cli, bool ok ) {
    return cli->sendStartResponse( ok );
}

bool szgClient_connected( arSZGClient* cli ) {
    return cli->connected();
}

