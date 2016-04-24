project("hello")
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

message("-- We are on ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}")
if (NOT CONFIGURED_ONCE)
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        message("-- Configured to use c++11")
        set(CMAKE_CXX_FLAGS "-std=c++11 ${warnings}"
            CACHE STRING "Flags used by the compiler during all build types." FORCE)
    else()
        set(CMAKE_CXX_FLAGS "-std=c++14 ${warnings}"
            CACHE STRING "Flags used by the compiler during all build types." FORCE)
    endif()
endif()

include_directories(include)
include_directories(deps/libressl/include)

add_library(libressl STATIC IMPORTED)
if (NOT MSVC)
    set_property(TARGET libressl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/deps/libressl/crypto/.libs/libcrypto.a)
else()
    if (MSVC_C_ARCHITECTURE_ID MATCHES 64 OR MSVC_CXX_ARCHITECTURE_ID MATCHES 64)
        set_property(TARGET libressl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/deps/libressl/x64/libcrypto-37.lib)
    else()
        set_property(TARGET libressl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/deps/libressl/x86/libcrypto-37.lib)
    endif()
endif()

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")
