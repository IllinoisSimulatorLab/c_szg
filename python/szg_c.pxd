from libc.stdint cimport uintptr_t


cdef extern from "szg_c.h":
    ctypedef struct arSZGClient:
        pass

    arSZGClient* szgClient()

    int init_szgClient( arSZGClient* cli, char* forcedName )

    void delete_szgClient( arSZGClient* cli )

