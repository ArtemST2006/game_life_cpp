cmake_minimum_required(VERSION 3.10)
project(Myproj)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.6.1 REQUIRED graphics window system)

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

add_executable(a src/main.cpp src/Field.cpp src/Cell.cpp src/Game.cpp src/utils.cpp)

target_link_libraries(a sfml-graphics sfml-window sfml-system)