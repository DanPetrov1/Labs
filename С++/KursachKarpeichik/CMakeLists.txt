cmake_minimum_required(VERSION 3.15)
project(KursachKarpeichik)

set(CMAKE_CXX_STANDARD 11)

add_executable(KursachKarpeichik main.cpp Sources/Salary.cpp Headers/Salary.h Headers/MyException.h
        Sources/InputError.cpp Headers/InputError.h Sources/Specialist.cpp Headers/Specialist.h Headers/List.h
        Headers/Algorithm.h Headers/Interface.h Headers/ListException.h Sources/User.cpp Headers/User.h Headers/File.h
        Sources/Supervisor.cpp Headers/Supervisor.h Sources/Trainee.cpp Headers/Trainee.h)