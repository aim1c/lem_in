cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(lem_in)				# Название проекта

set(SOURCE_EXE main.c lem_in.h parse_from_file.c error.h error.c)

add_executable(lem_in ${SOURCE_EXE})	# Создает исполняемый файл с именем main

include_directories(includes)

add_subdirectory(libft) # Добавление подпроекта, указывается имя дирректории

target_link_libraries(lem_in libft)		# Линковка программы с библиотекой
