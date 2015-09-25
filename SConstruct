# NOTE: Assumes syzygy was built with SZG_LINKING='STATIC'
import os
import sys

env = Environment()

szgIncPath = '#/include/'
szgLibPath = '#/lib/'+sys.platform
buildPath = '#/build/'+sys.platform

env.VariantDir(buildPath,'src')


szgLibs = ['arDrivers_static','arBarrier_static',
    'arPhleet_static','arMath_static','arLanguage_static']

sourceFiles = [os.path.join( buildPath, f ) for f in os.listdir('src') if os.path.splitext(f)[1] == '.cpp']


#fmodPath = os.path.join( os.environ['SZGEXTERNAL'], 'win32', 'fmod-4' )
#fmodIncPath = os.path.join( fmodPath, 'include' )
#fmodLibPath = os.path.join( fmodPath, 'lib' )
#fmodLibs = ['fmodex']

if sys.platform == 'win32':
    if os.environ['SZG_COMPILER'] == 'MINGW':
        ccFlags = ['-O2','-Wall','-W','-Wpointer-arith','-march=i686','-D AR_USE_WIN_32','-D AR_USE_MINGW']
        linkFlags = ['-static-libgcc','-static-libstdc++','-Wl,--enable-stdcall-fixup']
        sysLibs = ['winmm','gdi32','wsock32']
    else:
        raise NotImplementedError, "Need to add compile/link flags for visual C++"
else:
    raise NotImplementedError, "Need to add compile/link flags for this platform"

ccPath = [szgIncPath]
libPath = [szgLibPath]
libs = szgLibs+sysLibs

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
sharedLib = env.SharedLibrary( 'szg_c', sourceFiles )

