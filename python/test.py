from __future__ import print_function
import szgc

cfg = szgc.SzgConfig()
print( "Reading...", cfg.read() )
print ( "Computer:", cfg.computerName )
print ( "User    :", cfg.userName )
print ( "Server  :", cfg.serverName )
print ( "ServerIP:", cfg.serverIPAddress )
print ( "Port    :", cfg.serverPort )
del cfg

cli = szgc.SzgClient()
print( "connect:", cli.connect() )
cli.disconnect()
del cli

