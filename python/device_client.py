from __future__ import print_function
import sys
from time import sleep
import szgc


def main():
    szgc.szgSetLogLevel( "DEBUG", True )

    szgClient = szgc.SzgClient()
    szgClient.simpleHandshaking( False )
    print( "Connecting...")
    fInit = szgClient.connect( forcedName="device_client" )

    if not fInit:
        print( "SzgClient failed to init" )
        return szgClient.failStandalone( fInit )

    if not szgClient.connected:
        print( "SzgClient failed to connect" )
        return szgClient.failStandalone( fInit )

    print( "sendInitResponse()...")
    if not szgClient.sendInitResponse( False ):
        print( "device_client.py error: maybe szgserver died." )
        sys.exit(1)

    src = szgc.SzgNetInput()
    if not src.setSlot( 0 ):
        print( "device_client.py: invalid slot {}".format( 0 ) )
        szgClient.disconnect()
        sys.exit(1)

    print( "DeviceClient listening on slot {}".format( 0 ) )

    inputNode = szgc.SzgInputNode()

    print( "addInputSource()..." )
    inputNode.addInputSource( src, False )

    szgc.szgSetLogLevel( "DEBUG", True )

    print( "inputNode.init()..." )
    if not inputNode.init( szgClient ):
        print( "Failed to init SzgInputNode" )
        szgClient.disconnect()
        sys.exit(1)

    print( "sleep()" )
    sleep(.5)

    print( "inputNode.start()..." )
    if not inputNode.start():
        if not szgClient.sendStartResponse( False ):
            print( "device_client.py error: maybe szgserver died." )
        szgClient.disconnect()
        sys.exit(1)

    sleep(2.)
    if not src.connected:
        print( "device_client.py not yet connected on slot {}".format( 0 ) )

    if not szgClient.sendStartResponse( True ):
        print( "device_client.py error: maybe szgserver died." )
        szgClient.disconnect()
        sys.exit(1)

    try:
        while szgClient.connected:
            print( "Matrix 0" )
            print( inputNode.getMatrix(0) )
            print()
            sleep(.25)
    except Exception, msg:
        print( "The following exception occurred:" )
        print( msg )
        inputNode.stop()
        szgClient.disconnect()
        sys.exit(0)


if __name__ == '__main__':
    main()
