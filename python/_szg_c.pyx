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


def szgSetLogLevel( char* level, int fVerbose ):
    return szg_c.setLogLevel( level, fVerbose )


cdef class SzgConfig:
    cdef szg_c.arPhleetConfig* _cfg

    def __cinit__( self ):
        self._cfg = szg_c.szgConfig()
        if not self._cfg:
            raise RuntimeError, "SzgConfig() failed to create arPhleetConfif()"

    def __dealloc__( self ):
        szg_c.szgConfig_delete( self._cfg )

    def getPtr( self ):
        return <uintptr_t>(self._cfg)

    def read( self ):
        if not szg_c.szgConfig_read( self._cfg ):
            print "SzgConfig failed to read config"
            return False
        if not szg_c.szgConfig_readLogin( self._cfg ):
            print "SzgConfig failed to read login"
            return False
        return True

    property computerName:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getComputerName( self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property userName:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getUserName( self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property serverName:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getServerName( self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property serverIPAddress:
        def __get__( self ):
            cdef char* buf = szg_c.szgConfig_getServerIP( self._cfg )
            cdef bytes val = buf
            szg_c.free_ptr( <void*>buf )
            return val

    property serverPort:
        def __get__( self ):
            return szg_c.szgConfig_getServerPort( self._cfg )




cdef class SzgClient:
    cdef szg_c.arSZGClient* _client

    def __cinit__( self ):
        self._client = szg_c.szgClient()

    def __dealloc__( self ):
        szg_c.szgClient_delete( self._client )

    def getPtr( self ):
        return <uintptr_t>(self._client)

    def simpleHandshaking( self, int state ):
        szg_c.szgClient_simpleHandshaking( self._client, state )

    def connect( self, char* forcedName="foo" ):
        return szg_c.szgClient_connect( self._client, forcedName )

    def disconnect( self ):
        szg_c.szgClient_disconnect( self._client )

    def failStandalone( self, int fInited ):
        szg_c.szgClient_failStandalone( self._client, fInited )

    def sendInitResponse( self, int ok ):
        return szg_c.szgClient_sendInitResponse( self._client, ok )

    def sendStartResponse( self, int ok ):
        return szg_c.szgClient_sendStartResponse( self._client, ok )

    property connected:
        def __get__( self ):
            return szg_c.szgClient_connected( self._client )



cdef class SzgNetInput:
    cdef szg_c.arNetInputSource* _nis

    def __cinit__( self ):
        self._nis = szg_c.szgNetInput()

    def __dealloc__( self ):
        szg_c.szgNetInput_delete( self._nis )

    def getPtr( self ):
        return <uintptr_t>(self._nis)

    def setSlot( self, unsigned int slot ):
        return szg_c.szgNetInput_setSlot( self._nis, slot )

    def setServiceName( self, char* name ):
        return szg_c.szgNetInput_setServiceName( self._nis, name )

    property connected:
        def __get__( self ):
            return szg_c.szgNetInput_connected( self._nis )



cdef class SzgInputNode:
    cdef szg_c.arInputNode* _nod

    def __cinit__( self ):
        self._nod = szg_c.szgInputNode(False)

    def __dealloc__( self ):
        szg_c.szgInputNode_delete( self._nod )

    def getPtr( self ):
        return <uintptr_t>(self._nod)

    def addInputSource( self, src, int iOwnIt ):
        cdef uintptr_t inpPtr = src.getPtr()
        szg_c.szgInputNode_addInputSource( self._nod, <szg_c.arNetInputSource*>inpPtr, iOwnIt )
        
    def init( self, cli ):
        cdef uintptr_t cliPtr = cli.getPtr()
        return szg_c.szgInputNode_init( self._nod, <szg_c.arSZGClient*>cliPtr )

    def start( self ):
        return szg_c.szgInputNode_start( self._nod )

    def stop( self ):
        return szg_c.szgInputNode_stop( self._nod )

    property numberButtons:
        def __get__( self ):
            return szg_c.szgInputNode_getNumberButtons( self._nod )

    property numberAxes:
        def __get__( self ):
            return szg_c.szgInputNode_getNumberAxes( self._nod )

    property numberMatrices:
        def __get__( self ):
            return szg_c.szgInputNode_getNumberMatrices( self._nod )

    def getButton( self, int index ):
        return szg_c.szgInputNode_getButton( self._nod, index )

    def getAxis( self, int index ):
        return szg_c.szgInputNode_getAxis( self._nod, index )

    def getMatrix( self, int index ):
        cdef float* buf = szg_c.szgInputNode_getMatrix( self._nod, index )
        cdef np.ndarray arr = np.zeros( (4,4), dtype=np.float32 )
        cdef Py_ssize_t i, j
        cdef int ind = 0
        for i in range(4):
            for j in range(4):
                arr[i,j] = buf[ind]
                ind += 1
        szg_c.free_ptr( <void*>buf )
        return arr

    
