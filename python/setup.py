from __future__ import print_function
from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
import os


currDir = os.getcwd()
rootDir = os.path.dirname( currDir )

szgIncDir = os.path.join( rootDir, 'include' )
szgcIncDir = os.path.join( rootDir, 'src' )
szgLibDir = os.path.join( rootDir, 'lib', sys.platform )


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

