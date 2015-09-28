from libc.stdint cimport uintptr_t

# import szg_c.pxd
cimport szg_c


cdef class SzgConfig:
    cdef uintptr_t _cfg

    def __cinit__( self ):
        self._cfg = <uintptr_t>szg_c.szgConfig()
        if not self._cfg:
            raise RuntimeError, "SzgConfig() failed to create arPhleetConfif()"

    def __dealloc__( self ):
        szg_c.szgConfig_delete( <szg_c.arPhleetConfig*>self._cfg )

    def read( self ):
        if not szg_c.szgConfig_read( <szg_c.arPhleetConfig*>self._cfg ):
            print "SzgConfig failed to read config"
            return False
        if not szg_c.szgConfig_readLogin( <szg_c.arPhleetConfig*>self._cfg ):
            print "SzgConfig failed to read login"
            return False
        return True

    property computerName:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getComputerName( <szg_c.arPhleetConfig*>self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property userName:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getUserName( <szg_c.arPhleetConfig*>self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property serverName:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getServerName( <szg_c.arPhleetConfig*>self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property serverIPAddress:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getServerIP( <szg_c.arPhleetConfig*>self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property serverPort:
        def __get__( self ):
            return szg_c.szgConfig_getServerPort( <szg_c.arPhleetConfig*>self._cfg )




cdef class SzgClient:
    cdef uintptr_t _client

    def __cinit__( self ):
        self._client = <uintptr_t>szg_c.szgClient()

    def __dealloc__( self ):
        szg_c.szgClient_delete( <szg_c.arSZGClient*>self._client )

    def connect( self, char* forcedName="foo" ):
        return szg_c.szgClient_connect( <szg_c.arSZGClient*>self._client, forcedName )

    def disconnect( self ):
        szg_c.szgClient_disconnect( <szg_c.arSZGClient*>self._client )

    def sendInitResponse( self, int ok ):
        return szg_c.szgClient_sendInitResponse( <szg_c.arSZGClient*>self._client, ok )

    def sendStartResponse( self, int ok ):
        return szg_c.szgClient_sendStartResponse( <szg_c.arSZGClient*>self._client, ok )

    property connected:
        def __get__( self ):
            return szg_c.szgClient_connected( <szg_c.arSZGClient*>self._client )

