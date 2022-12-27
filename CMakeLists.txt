cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME sfml)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("SFML/include/")	# добавляем директории
include_directories("inc/")
link_directories("SFML/lib/")	

add_executable("${PROJECT_NAME}" sfml.cpp Game.h Game.cpp)

file(COPY "materials" DESTINATION "/")
file(COPY "fonts" DESTINATION "/")
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s
						  sfml-window-s
						  sfml-system-s
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
						  
