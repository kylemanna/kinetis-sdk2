multicore/erpc/readme.txt

This folder contains source code for the Embedded Remoted Procedure Call
framework, and for the eRPC code generator tool, erpcgen.

Up to date eRPC source files can be found on https://github.com/EmbeddedRPC/erpc.

There are several makefiles in this erpc/ directory. The primary makefile
is stored in root of erpc directory. The other makefiles are stored in subdirectories.
For example, erpc/erpcgen/Makefile builds the erpcgen tool, and can be built by running:
$make erpcgen
in the multicore/erpc/ directory.
Erpcgen is also the default build target, and can be run by only invoking:
$make
in the multicore/erpc/ directory. These makefiles are compatible with gcc on
Linux, OS X, MinGW, and Cygwin. A Windows build using Visual Studio is also
available in the multicore/erpcgen/VisualStudio_v12/ directory.
There is also an Xcode project file in the multicore/erpc/erpcgen/ directory which
can be used to build erpcgen for OS X.

doc - Holds the documentation.
erpc_c - Holds source C-code for the eRPC infrastructure.

erpc_python - Holds source PY-code for the eRPC infrastructure.

erpcgen - Holds source code for erpcgen and makefiles, project files for Visual Studio
to build erpcgen on Windows, Linux and OS X.

mk - Contains common makefiles for building eRPC components.

Need to do before running make first time:
MinGW:
    MingGW should be placed in C:\MinGW folder. Install in mingw enviroment
    mingw32-make, ming32-gcc, mingw32-g++. In Windows enviroment install Python.
    Unzip multicore/erpc/windows/win_flex_bison-latest.zip into same directory
    (without subdirectory). Download and build boost libraries into
    C:\boost_1_57_0 folder.
    Add this path to Windows PATH enviroment variable: C:\MinGW\bin.
    Call mingw32-make instead of make from the command line.

Visual Studio:
    Steps are described in multicore/erpc/erpcgen/VisualStudio_v12/ReadMeErpcgen.txt

Rest:
    Install:    bison: GNU yacc-complatible parser generator
                flex: A fast lexical analyzer generator
                libboost-devel: Boost C++ libraries
                make: the GNU version of the 'make' utility
                python: Python language interpreter
                gcc-core: GNU Compiler Collection (C, OpenMP)
                gcc-g++: GNU Compiler Collection (C++)

        !Linux need use libboost version 1.58.0.
