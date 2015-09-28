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
    int szgClient_sendInitResponse( arSZGClient* cli, int ok )
    int szgClient_sendStartResponse( arSZGClient* cli, int ok )
    int szgClient_connected( arSZGClient* cli )


    ctypedef struct arNetInputSource:
        pass

    arNetInputSource* szgNetInput()
    void szgNetInput_delete( arNetInputSource* nis )
    # Only use ONE OR THE OTHER of these two!
    int szgNetInput_setSlot( arNetInputSource* nis, unsigned int slot )
    int szgNetInput_setServiceName( arNetInputSource* nis, const char* name )
    int szgNetInput_connected( arNetInputSource* nis )


    ctypedef struct arInputNode:
        pass

    arInputNode* szgInputNode( int bufferEvents )
    void szgInputNode_delete( arInputNode* nod )

    int szgInputNode_init( arInputNode* nod, arSZGClient* cli )
    int szgInputNode_start( arInputNode* nod )
    int szgInputNode_stop( arInputNode* nod )

    int szgInputNode_getNumberButtons( arInputNode* nod )
    int szgInputNode_getNumberAxes( arInputNode* nod )
    int szgInputNode_getNumberMatrices( arInputNode* nod )

    int szgInputNode_getButton( arInputNode* nod, int index )
    float szgInputNode_getAxis( arInputNode* nod, int index )
    float* szgInputNode_getMatrix( arInputNode* nod, int index )
    

