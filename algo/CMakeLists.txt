cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.
project(lem_in)				# Название проекта
set(CMAKE_C_STANDARD 99)

add_executable(lem_in main.c lem_in.h read.c)
add_subdirectory(libft) # Добавление подпроекта, указывается имя дирректории

target_link_libraries(lem_in libft)