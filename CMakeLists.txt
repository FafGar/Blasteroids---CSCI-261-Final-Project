cmake_minimum_required(VERSION 3.12)
project(finalProject)

set(CMAKE_CXX_STANDARD 14)

include_directories("C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/include")

add_executable(finalProject main.cpp Player.cpp Player.h Laser.cpp Laser.h Asteroid.cpp Asteroid.h Funcs.cpp Funcs.h Alien.cpp Alien.h)

target_link_directories(finalProject PUBLIC "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib")

target_link_libraries(finalProject sfml-graphics sfml-system sfml-window sfml-main)

# -lsfml-graphics -lsfml-window -lsfml-system

# cmake_minimum_required(VERSION 3.0.0)
# project(finalProject VERSION 0.1.0)

# include(CTest)
# enable_testing()


# add_compile_options(-pedantic -Wall -Wextra -municode -lsfml-graphics -lsfml-window -lsfml-system)
# add_executable(finalProject 
# main.cpp 
# Player.cpp 
# Player.h 
# Laser.cpp 
# Laser.h 
# Asteroid.cpp 
# Asteroid.h 
# Funcs.cpp 
# Funcs.h 
# Alien.cpp 
# Alien.h)



# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)