cmake_minimum_required(VERSION 3.15)
project(Exceptions)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exceptions main.cpp Sources/Business.cpp Headers/Business.h Sources/Businessman.cpp Headers/Businessman.h Sources/Person.cpp Headers/Person.h Sources/Tourist.cpp Headers/Tourist.h Sources/InputError.cpp Headers/InputError.h Headers/MyException.h Headers/MemoryError.h)