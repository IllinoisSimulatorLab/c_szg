from libc.stdint cimport uintptr_t
#from libc.stdlib cimport malloc, free

# import szg_c.pxd
cimport szg_c


cdef class SzgClient:
    cdef uintptr_t _client

    def __cinit__( self ):
        self._client = <uintptr_t>szg_c.szgClient()

    def connect( self, char* forcedName="foo" ):
        return szg_c.connect_szgClient( <szg_c.arSZGClient*>self._client, forcedName )

    def disconnect( self ):
        szg_c.disconnect_szgClient( <szg_c.arSZGClient*>self._client )

    def __dealloc__( self ):
        szg_c.delete_szgClient( <szg_c.arSZGClient*>self._client )


