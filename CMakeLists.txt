
cmake_minimum_required(VERSION 3.0.0)
project(finalProject VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("C:/C++ libraries/SFML-2.5.1/include")

add_executable(finalProject 
main.cpp 
Player.cpp 
Player.h 
Laser.cpp 
Laser.h 
Asteroid.cpp 
Asteroid.h 
Funcs.cpp 
Funcs.h 
Alien.cpp 
Alien.h)


target_link_directories(finalProject PUBLIC "C:/C++ libraries/SFML-2.5.1/lib")

target_link_libraries(finalProject sfml-graphics sfml-system sfml-window sfml-main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)