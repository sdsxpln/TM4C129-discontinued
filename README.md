This project is now terminated due to problems with the Texas Instruments license.    
We released a GPL _incompatible_ version instead @iot_tiva_template
https://github.com/Lindem-Data-Acquisition-AS/iot_tiva_template

Please contact us if there is any interest in continuing our work for a GPL compatible port for TM4C129 with lwIP.

    
    ***************************************************************************************
    LICENSE
    ***************************************************************************************

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


    ***************************************************************************************
    IMPORTANT INFORMATION
    ***************************************************************************************
    
    
    This project contains libraries released under the GPLv2 license. 
    Because of this all code is required to be compatible with the GPLv2 license.
    As a result, several files released by TI under the TivaWare_C_Series library
    can not be used, e.g. Makefile, startup_gcc.c and linker file.
    
    3rd party libraries have been added for completeness. 
    
    The following 3rd party libraries in the "libraries" folder has been modified:
    There are no modifications beyond the ones listed below, however microcontroller ports 
    and library specific apps are included within the respective library directories.

    *   lwip-1.4.1\src\include\lwip\pbuf.h edited for the TI implemented LWIP_PTPD.
        if LWIP_PTPD is diabled in lwipopts.h, the default pbuf.h file can be used.
    
    
    ***************************************************************************************
    CURRENT STATUS
    ***************************************************************************************
    
    
    We have successfully implemented GPLv2 compatible alternatives for the 
    Makefile, startup_gcc and linker file for this project. We will upload these files 
    once we have finished integrating the libraries with a complete makefile example.
    These files will support the ARM GCC compiler, and works under Cygwin and Linux.
    We intend to support vanilla windows but... for now, just install Cygwin.
    
    Currently implementing Newlib support, as this is not done by TI as default. Newlib is 
    needed for runtime stats by FreeRTOS, as well as the FreeRTOS+CLI command register+++
    We are also finishing the lwIP library example with http server.
