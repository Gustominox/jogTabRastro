cmake_minimum_required(VERSION 3.15)
project(rastro C)

set(CMAKE_C_STANDARD 99)

add_executable(rastro main.c dados.h dados.c logica.c logica.h interface.c interface.h)