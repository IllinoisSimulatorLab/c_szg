from libc.stdint cimport uintptr_t

# Import the Python-level symbols of numpy
import numpy as np

# Import the C-level symbols of numpy
cimport numpy as np

# Numpy must be initialized. When using numpy from C or Cython you must
# _always_ do that, or you will have segfaults
np.import_array()

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

    property ptr:
        def __get__( self ):
            return self._client



cdef class SzgNetInput:
    cdef uintptr_t _nis

    def __cinit__( self ):
        self._nis = <uintptr_t>szg_c.szgNetInput()

    def __dealloc__( self ):
        szg_c.szgNetInput_delete( <szg_c.arNetInputSource*>self._nis )

    def setSlot( self, unsigned int slot ):
        return szg_c.szgNetInput_setSlot( <szg_c.arNetInputSource*>self._nis, slot )

    def setServiceName( self, char* name ):
        return szg_c.szgNetInput_setServiceName( <szg_c.arNetInputSource*>self._nis, name )

    property connected:
        def __get__( self ):
            return szg_c.szgNetInput_connected( <szg_c.arNetInputSource*>self._nis )
        

cdef class SzgInputNode:
    cdef uintptr_t _nod

    def __cinit__( self ):
        self._nod = <uintptr_t>szg_c.szgInputNode(False)

    def __dealloc__( self ):
        szg_c.szgInputNode_delete( <szg_c.arInputNode*>self._nod )

    def init( self, cli ):
        return szg_c.szgInputNode_init( <szg_c.arInputNode*>self._nod, <szg_c.arSZGClient*>cli.ptr )

    def start( self ):
        return szg_c.szgInputNode_start( <szg_c.arInputNode*>self._nod )

    def stop( self ):
        return szg_c.szgInputNode_stop( <szg_c.arInputNode*>self._nod )

    property numberButtons:
        def __get__( self ):
            return szg_c.szgInputNode_getNumberButtons( <szg_c.arInputNode*>self._nod )

    property numberAxes:
        def __get__( self ):
            return szg_c.szgInputNode_getNumberAxes( <szg_c.arInputNode*>self._nod )

    property numberMatrices:
        def __get__( self ):
            return szg_c.szgInputNode_getNumberMatrices( <szg_c.arInputNode*>self._nod )

    def getButton( self, int index ):
        return szg_c.szgInputNode_getButton( <szg_c.arInputNode*>self._nod, index )

    def getAxis( self, int index ):
        return szg_c.szgInputNode_getAxis( <szg_c.arInputNode*>self._nod, index )

    def getMatrix( self, int index ):
        cdef float* buf = szg_c.szgInputNode_getMatrix( <szg_c.arInputNode*>self._nod, index )
        cdef np.ndarray arr = np.zeros( (4,4), dtype=np.float32 )
        cdef Py_ssize_t i, j
        cdef int ind = 0
        for i in range(4):
            for j in range(4):
                arr[i,j] = buf[ind]
                ind += 1
        szg_c.free_ptr( <void*>buf )
        return arr
