cmake_minimum_required(VERSION 3.13)
project(Biblioteka)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(Biblioteka main.cpp ConsoleInterface.cpp ConsoleInterface.h LibraryManager.cpp LibraryManager.h BookModel.cpp BookModel.h Interfaces/IDataSource.h DataSource.cpp DataSource.h)
