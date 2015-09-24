# c_szg
C API for a subset of szg (for easier interfacing w. other environments)

Uses scons to build, I only know that it builds in Aszgard so far. Exposes a whopping 3 functions so far.

Szg headers are included in include/, empty lib/(platform)/ directories into which you should drop the libraries.

Output is in build/(platform)/.

NOTE: The `env.VariantDir()` call in SConstruct causes everything to be copied from src/ to build/(platform) before building, which is why you may see error messages referring to source files in build/. Edit the corresponding files in src/.

Includes a set of Python bindings for testing purposes. Building those requires Cython, and running the included unit tests requires pytest.
