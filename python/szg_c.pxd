from libc.stdint cimport uintptr_t


cdef extern from "szg_c.h":
    ctypedef struct arSZGClient:
        pass

    arSZGClient* szgClient()

    int connect_szgClient( arSZGClient* cli, char* forcedName )

    void disconnect_szgClient( arSZGClient* cli )

    void delete_szgClient( arSZGClient* cli )

