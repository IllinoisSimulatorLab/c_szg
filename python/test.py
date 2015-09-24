from __future__ import print_function
import szgc

c = szgc.SzgClient()
print( "Init:", c.init() )
del c

