from __future__ import print_function
from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
import os
import shutil


currDir = os.getcwd()
rootDir = os.path.dirname( currDir )

szgIncDir = os.path.join( rootDir, 'include' )
szgcIncDir = os.path.join( rootDir, 'src' )
szgLibDir = os.path.join( rootDir, 'lib', sys.platform )


# Make sure szg_c.dll is current
dllPath = os.path.join( currDir, 'szg_c.dll' )
dllBuildPath = os.path.join( rootDir, 'szg_c.dll' )

if not os.path.exists( dllPath ):
    if not os.path.exists( dllBuildPath ):
        raise OSError, "shared library szg_c.dll does not exist, you need to run 'scons' in the parent directory"
    else:
        print( "Copying '{}' to '{}'...".format( dllBuildPath, dllPath ) )
        shutil.copyfile( dllBuildPath, dllPath )

elif not os.path.exists( dllBuildPath ):
    print( "WARNING:  shared library '{}' does not exist".format( dllBuildPath ) )
else:
    currentDllctime = os.stat( dllPath )
    buildDllctime = os.stat( dllBuildPath )
    if currentDllctime < buildDllctime:
        print( "Copying '{}' to '{}'...".format( dllBuildPath, dllPath ) )
        shutil.copyfile( dllBuildPath, dllPath )



szgLibs = ['arDrivers_static','arBarrier_static',
    'arPhleet_static','arMath_static','arLanguage_static']

cyExtension = Extension('_szg_c', \
    ['_szg_c.pyx'], \
    language = 'c++', \
    extra_compile_args = ["-D AR_USE_WIN_32","-D AR_USE_MINGW","-D _WIN32"], \
    include_dirs = [szgcIncDir,szgIncDir], \
    libraries = ['szg_c']+szgLibs, \
    library_dirs = [currDir,szgLibDir] )


setup(
    name = "szg_c",
    ext_modules = cythonize(cyExtension)
)

