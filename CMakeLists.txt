cmake_minimum_required(VERSION 3.13)
project(Biblioteka)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblioteka main.cpp ConsoleInterface.cpp ConsoleInterface.h LibraryManager.cpp LibraryManager.h Book.cpp Book.h)