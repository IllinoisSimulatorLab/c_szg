from __future__ import print_function
import os
import sys
import getpass

import pytest
import xmltodict

import szgc
from find_program import find_program

szgserverMissing = find_program('szgserver') is None

szgserver_found = pytest.mark.skipif( szgserverMissing, \
                        reason="Failed to find szgserver on exec path")


@szgserver_found
def test_find_server():
    """Demonstrates usage of custom skip predicates..."""
    pass


@pytest.fixture(scope='module')
def get_config_data():
    """
    Looks like:
<computer>
  <name>computer_name</name>
</computer>

<interface>
  <type>IP</type>
  <name>internet</name>
  <address>127.0.0.1</address>
  <mask>255.255.255.0</mask>
</interface>

<ports>
  <first>
    4700 
  </first>
  <size>
    200 
  </size>
</ports>
"""    
    defaultConfigPathDict = {'win32':'c:/szg','linux':'/tmp'}
    configDirPath = os.environ.get( 'SZG_CON', defaultConfigPathDict[sys.platform] )
    configFilepath = os.path.join( configDirPath, 'szg.conf' )
    try:
        with open( configFilepath, 'r' ) as f:
            s = f.read()
    except IOError:
        return {'computer':{'name':'NULL'}}
    s = '<conf>'+s+'</conf>' # to make it valid XML
    return xmltodict.parse(s)['conf']


@pytest.fixture(scope='module')
def get_login_data():
    """
    Looks like:
<login>
  <user>me</user>
  <server_name>aszgard</server_name>
  <server_IP>127.0.0.1</server_IP>
  <server_port>
    8888 
  </server_port>
</login>
"""    
    defaultConfigPathDict = {'win32':'c:/szg','linux':'/tmp'}
    configDirPath = os.environ.get( 'SZG_LOGIN', defaultConfigPathDict[sys.platform] )
    username = getpass.getuser()
    configFilepath = os.path.join( configDirPath, 'szg_{}.conf'.format(username) )
    try:
        with open( configFilepath, 'r' ) as f:
            s = f.read()
    except IOError:
        return {'user':'NULL','server_name':'NULL','server_IP':'NULL','server_port':0}
    return xmltodict.parse(s)['login']


@pytest.fixture(scope='module')
def get_szg_config():
    cfg = szgc.SzgConfig()
    cfg.read()
    return cfg



def test_computer_name(get_szg_config,get_config_data):
    assert( get_szg_config.computerName == str(get_config_data['computer']['name']) )


def test_login(get_szg_config,get_login_data):
    assert( get_szg_config.userName == str(get_login_data['user']) )
    assert( get_szg_config.serverName == str(get_login_data['server_name']) )
    assert( get_szg_config.serverIPAddress == str(get_login_data['server_IP']) )
    assert( get_szg_config.serverPort == int(get_login_data['server_port']) )


