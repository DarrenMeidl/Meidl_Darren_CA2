cmake_minimum_required(VERSION 3.27)
project(Meidl_Darren_CA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Meidl_Darren_CA2 main.cpp
        Bug.cpp
        Bug.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML-2.6.1/include)
target_link_libraries(Meidl_Darren_CA2 sfml-system sfml-window sfml-graphics sfml-audio)