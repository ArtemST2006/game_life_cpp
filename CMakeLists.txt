cmake_minimum_required(VERSION 3.10)
project(Myproj)

set(CMAKE_CXX_STANDARD 17)


find_package(SFML 2.6.1 REQUIRED graphics window system)

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

find_package(yaml-cpp REQUIRED)

add_executable(a src/main.cpp src/game/Field.cpp src/game/Cell.cpp src/game/Game.cpp src/utils/utils.cpp src/game/sett.cpp)

target_link_libraries(a sfml-graphics sfml-window sfml-system)
target_link_libraries(a yaml-cpp)