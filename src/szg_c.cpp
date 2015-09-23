#include <string>
#include "arSZGClient.h"

#ifdef AR_USE_WIN_32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif


std::string _bufString;

char* argvG[] = {"unity"};
int argcG = 1;


extern "C" {
    arSZGClient* EXPORT_API szgClient() {
        return new arSZGClient();
    }

    int EXPORT_API init_szgClient( arSZGClient* cli, char* forcedName ) {
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
            
    void EXPORT_API delete_szgClient( arSZGClient* cli ) {
        if (cli == NULL) {
            return;
        }
        delete cli;
    }
}


