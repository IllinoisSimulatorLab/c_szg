#include "szg_c.h"

#include <string>

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


