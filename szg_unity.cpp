#include "arSZGClient.h"

#define EXPORT_API __declspec(dllexport)


extern "C" {
    arSZGClient* EXPORT_API szgClient() {
        return new arSZGClient();
    }

    void EXPORT_API delSzgClient( arSZGClient* cli ) {
        if (cli == NULL) {
            return;
        }
        delete cli;
    }
}


