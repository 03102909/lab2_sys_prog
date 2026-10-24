cmake_minimum_required(VERSION 3.29)
project(sys_prog)

set(CMAKE_CXX_STANDARD 20)

add_executable(prog_unopt main.cpp)
target_compile_options(prog_unopt PRIVATE -O0)

add_executable(prog_opt main.cpp)
target_compile_options(prog_opt PRIVATE -O3 -mcpu=native)
target_compile_definitions(prog_opt PRIVATE USE_OPT) # Кажемо коду використати швидку функцію