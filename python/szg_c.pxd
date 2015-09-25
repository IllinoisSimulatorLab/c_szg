from libc.stdint cimport uintptr_t


cdef extern from "szg_c.h":

    void free_ptr( void* ptr )
    
    ctypedef struct arPhleetConfig:
        pass

    arPhleetConfig* szgConfig()

    void szgConfig_delete( arPhleetConfig* cfg )

    int szgConfig_read( arPhleetConfig* cfg )
    int szgConfig_write( arPhleetConfig* cfg )

    int szgConfig_readLogin( arPhleetConfig* cfg )
    int szgConfig_writeLogin( arPhleetConfig* cfg )

    char* szgConfig_getComputerName( arPhleetConfig* cfg )
    char* szgConfig_getUserName( arPhleetConfig* cfg )
    char* szgConfig_getServerName( arPhleetConfig* cfg )
    char* szgConfig_getServerIP( arPhleetConfig* cfg )
    int szgConfig_getServerPort( arPhleetConfig* cfg )


    ctypedef struct arSZGClient:
        pass

    arSZGClient* szgClient()

    int szgClient_connect( arSZGClient* cli, char* forcedName )

    void szgClient_disconnect( arSZGClient* cli )

    void szgClient_delete( arSZGClient* cli )

