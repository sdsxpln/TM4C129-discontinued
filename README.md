    TM4C129 FreeRTOS (w/ lwIP/HTTP server & FreeRTOS+IO/CLI)

    Copyright (C) 2014  Lindem Data Acquisition AS

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

    website:  www.LDA.as
    email:    joakim.myrland@LDA.as
    project:  https://github.com/Lindem-Data-Acquisition-AS/TM4C129/


    ***************************************************************************
    
    
    This project contains libraries released under the GPLv2 license. 
    Because of this all code is required to be compatible with the GPLv2 license.
    As a result, several files released by TI under the TivaWare_C_Series library
    can not be used, e.g. Makefile, startup_gcc.c and linker file.
    We are currently trying to find/make GPLv2 compatible files for this project.
    These files will support the ARM GCC compiler.
    There will be no "official" support for other compilers.

    3rd party libraries have been added for completeness. 
    
    The following 3rd party libraries in the "libraries" folder has been modified:
    There are no modifications beyond the ones listed below, however microcontroller ports 
    and library specific apps are included within the respective library directories.

    *   lwip-1.4.1\src\include\lwip\pbuf.h edited for the TI implemented LWIP_PTPD.
        if LWIP_PTPD is diabled in lwipopts.h, the default pbuf.h file can be used.
    
    
