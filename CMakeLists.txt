project("hello")
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
endif()

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include_directories(include)
include_directories(deps/libressl/include)

add_library(libressl STATIC IMPORTED)
set_property(TARGET libressl PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/deps/libressl/crypto/.libs/libcrypto.a)

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")
