cmake_minimum_required(VERSION 3.0)

project(ADSLecture10_Demos CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ex1_person
        ex1_person/main.cpp
        ex1_person/person.h
        ex1_person/person.cpp
    )

add_executable(ex2_virtual
        ex2_virtual/main.cpp
        ex2_virtual/person.h
        ex2_virtual/person.cpp
    )

add_executable(ex3_interfaces
        ex3_interfaces/main.cpp
        ex3_interfaces/person.h
        ex3_interfaces/person.cpp
        ex3_interfaces/stringable.h
        ex3_interfaces/mystring.h
        ex3_interfaces/mystring.cpp
        ex3_interfaces/safe_array.hpp
    )

add_executable(ex4_abstract
        ex4_abstract/main.cpp
        ex4_abstract/person.h
        ex4_abstract/person.cpp
    )

add_executable(ex5_vtable
        ex5_vtable/main.cpp
    )