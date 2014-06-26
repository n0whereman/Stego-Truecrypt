This archive contains the source code of TrueCrypt 7.1a.

Linux and Mac OS X
======================

Requirements for Building TrueCrypt for Linux and Mac OS X:
-----------------------------------------------------------

- GNU Make
- GNU C++ Compiler 4.0 or compatible
- Apple Xcode (Mac OS X only)
- NASM assembler 2.08 or compatible (x86/x64 architecture only)
- pkg-config
- wxWidgets 2.8 shared library and header files installed or
  wxWidgets 2.8 library source code (available at http://www.wxwidgets.org)
- FUSE library and header files (available at http://fuse.sourceforge.net
  and http://code.google.com/p/macfuse)
- RSA Security Inc. PKCS #11 Cryptographic Token Interface (Cryptoki) 2.20
  header files (available at ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-11/v2-20)
  located in a standard include path or in a directory defined by the
  environment variable 'PKCS11_INC'


Requirements for Building Stegostorage for Linux and Mac OS X:
--------------------------------------------------------------
- Qt5 SDK
- libjpeg-turbo (libjpeg) - http://libjpeg-turbo.virtualgl.org
- FUSE
    - FUSE for Linux: http://fuse.sourceforge.net
    - OSXFUSE for Mac OS X: http://osxfuse.github.io 

    
Building Instructions for StegoDisk on Linux and Mac OS X:
----------------------------------------------------------
- Build StegoDiskCore library
  - cd src/StegoDiskCore
  - qmake
  - make
  
> output: bin/StegoDiskCore/release/libStegoDiskCore.a  

Instructions for Building TrueCrypt for Linux and Mac OS X:
-----------------------------------------------------------
1) Copy static library bin/StegoDiskCore/release/libStegoDiskCore.a to stegotruecrypt/Lib/StegoLib/Lib

2) Copy *.h from stegodisk/src/StegoDiskCore/ to stegotruecrypt/Lib/StegoLib/Inc/ (keep structure of DIRs)

3) Change the current directory to the root of the TrueCrypt source code.

4) If you have no wxWidgets shared library installed, run the following
   command to configure the wxWidgets static library for TrueCrypt and to
   build it: 

   $ make WX_ROOT=/usr/src/wxWidgets wxbuild

   The variable WX_ROOT must point to the location of the source code of the
   wxWidgets library. Output files will be placed in the './wxrelease/'
   directory.

5) To build TrueCrypt, run the following command:

   $ make

   or if you have no wxWidgets shared library installed:
   
   $ make WXSTATIC=1

6) If successful, the TrueCrypt executable should be located in the directory
   'Main'.

By default, a universal executable supporting both graphical and text user
interface is built. To build a console-only executable, which requires no GUI
library, use the 'NOGUI' parameter:

   $ make NOGUI=1 WX_ROOT=/usr/src/wxWidgets wxbuild
   $ make NOGUI=1 WXSTATIC=1
