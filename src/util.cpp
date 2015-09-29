#include "szg_c.h"
#include "arLogStream.h"
#include <string>


char* _stringToBuf( std::string& str ) {
    char* buf = (char*)malloc( str.size()+1 );
    memcpy( buf, str.c_str(), str.size()+1 );
    return buf;
}


void free_ptr( void* ptr ) {
    free( ptr );
}


bool setLogLevel( char* level, bool fVerbose ) {
    std::string str( level );
    return ar_setLogLevel( str, fVerbose );
}

