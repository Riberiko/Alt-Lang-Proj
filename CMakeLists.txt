cmake_minimum_required(VERSION 3.25)
project(CellProject)

set(CMAKE_CXX_STANDARD 14)


add_executable(Main src/main.cpp)
add_executable(Test tests/test.cpp)
add_library(MyLib src/Cell.cpp src/Cell.h src/Driver.cpp src/Driver.h)

target_link_libraries(Main MyLib)
target_link_libraries(Test MyLib)

