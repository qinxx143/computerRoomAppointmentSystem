cmake_minimum_required(VERSION 3.19)
project(p282_computerRoomAppointmentSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(p282_computerRoomAppointmentSystem main.cpp Identity.h Student.h Student.cpp Teacher.h Teacher.cpp Manager.h Manager.cpp globalFile.h ComputerRoom.h OrderFile.h OrderFile.cpp MenuInterface.h MenuInterface.cpp)