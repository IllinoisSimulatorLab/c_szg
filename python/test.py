from __future__ import print_function
import szgc

c = szgc.SzgClient()
print( "connect:", c.connect() )
c.disconnect()
del c

