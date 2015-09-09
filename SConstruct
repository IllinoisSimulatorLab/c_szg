# NOTE: Assumes syzygy was built with SZG_LINKING='STATIC'
import os
import sys

env = Environment()

# freeglut include and library paths
szgPath = os.path.join( os.environ['SZGHOME'] )
szgLibs = ['arDrivers_static','arBarrier_static',
    'arPhleet_static','arMath_static','arLanguage_static']

szgIncPath = os.path.join( szgPath, 'include', 'win32' )
szgLibPath = os.path.join( szgPath, 'lib', 'win32' )

fmodPath = os.path.join( os.environ['SZGEXTERNAL'], 'win32', 'fmod-4' )
fmodIncPath = os.path.join( fmodPath, 'include' )
fmodLibPath = os.path.join( fmodPath, 'lib' )
fmodLibs = ['fmodex']

ccFlags = ['-O2','-Wall','-W','-Wpointer-arith','-march=i686','-D AR_USE_WIN_32','-D AR_USE_MINGW']
linkFlags = ['-static-libgcc','-static-libstdc++','-Wl,--enable-stdcall-fixup']
sysLibs = ['winmm','gdi32','wsock32']

ccPath = [szgIncPath,fmodIncPath]
libPath = [szgLibPath,fmodLibPath]
libs = szgLibs+fmodLibs+sysLibs

ccFlags.append('-D AR_LINKING_STATIC')


# NOTE: If all sources are C files (as opposed to C++), then gcc will be called
# and will complain about the -static-libstdc++. It will still link, however.
flags = {'CCFLAGS':ccFlags,
    'CPPPATH':ccPath,
    'LIBPATH':libPath,
    'LIBS':libs,
    'LINKFLAGS':linkFlags}

env.MergeFlags( flags )
    
env['no_import_lib'] = True
# We'd like to be able to suppress creation of .def files for 
# driver plugins, but a bug in SCons causes the dll's to be
# re-linked every time if we do this.
#pluginEnv['WINDOWS_INSERT_DEF'] = False
#
# For now, in order to get things to work properly, we have to tell
# SCons to generate a .def file for the driver plugins, even though
# we don't need it, because otherwise a bug in SCons causes the
# plugins to be re-linked whether needed or not.
env['WINDOWS_INSERT_DEF'] = True


# Build all the 'normal' driver plugins.
# Each call to SharedLibrary() returns a (.dll,.a,.def) tuple.
pluginStuff = env.SharedLibrary( 'szg_unity.cpp' )


