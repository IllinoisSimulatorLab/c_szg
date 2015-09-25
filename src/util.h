#ifndef SZG_UTIL_H
#define SZG_UTIL_H

#include <string>


// NOT exposed
char* _stringToBuf( std::string& str );


extern "C" {

    void EXPORT_API free_ptr( void* ptr );
    
}

#endif
