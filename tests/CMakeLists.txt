include_directories(../include ../deps/catch)
add_test(testsay testsay)

add_executable(testsay say.cpp)
target_link_libraries(testsay hello libressl)
