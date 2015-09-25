#include "szg_c.h"


char* _stringToBuf( std::string& str ) {
    char* buf = (char*)malloc( str.size()+1 );
    memcpy( buf, str.c_str(), str.size()+1 );
    return buf;
}


void free_ptr( void* ptr ) {
    free( ptr );
}



