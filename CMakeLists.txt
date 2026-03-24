# vim:set sw=4 ts=8 et fileencoding=utf8:
# SPDX-License-Identifier: BSD-2-Clause
# SPDX-FileCopyrightText: 2026 Сергей Леонтьев (leo@sai.msu.ru)

cmake_minimum_required (VERSION 3.25)
project(orangec_setup
        VERSION 0.6.0
        DESCRIPTION
        "Use OrangeC in CMake project"
        HOMEPAGE_URL https://github.com/Serge3leo/orangec-setup.git
        LANGUAGES C)

option(WORKAROUND "CMake Orange C workaround" ON)
if (NOT CMAKE_C_COMPILER_ID STREQUAL OrangeC)
    message(FATAL_ERROR "Only for Orange C, strongly")
endif ()
if (WORKAROUND)
    string(REGEX REPLACE " +<FLAGS> +" " " warnd
        "${CMAKE_C_CREATE_SHARED_LIBRARY}")
    if (CMAKE_C_CREATE_SHARED_LIBRARY STREQUAL warnd)
        message(FATAL_ERROR "Workaround already applied")
    endif ()
    set(CMAKE_C_CREATE_SHARED_LIBRARY "${warnd}")
    message("WORKAROUND - OK")
elseif (CMAKE_C_CREATE_SHARED_LIBRARY MATCHES "<FLAGS>")
    message("WARNING: CMake don't have correct Orange C modules")
else ()
    message("OK: CMake have correct Orange C modules")
endif ()

set(HDRS mnld.h)
add_library(mnld SHARED ${HDRS} dll-mnld.c)
add_executable(main-mnld ${HDRS} main-mnld.c)
target_link_libraries(main-mnld mnld)

add_test(NAME main-mnld COMMAND main-mnld)
enable_testing()
