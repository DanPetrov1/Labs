cmake_minimum_required(VERSION 3.13)
project(Scholarship)

set(CMAKE_CXX_STANDARD 11)

add_executable(Scholarship Sourses/main.cpp Sourses/Student.cpp Headers/Student.h Headers/MyException.h
        Headers/InputError.h Sourses/InputError.cpp Sourses/Session.cpp Headers/Session.h Sourses/File.cpp
        Headers/File.h Sourses/List.cpp Headers/List.h Sourses/UndergraduateStudent.cpp Headers/UndergraduateStudent.h
        Sourses/GraduateStudent.cpp Headers/GraduateStudent.h Sourses/Interface.cpp Headers/Interface.h)