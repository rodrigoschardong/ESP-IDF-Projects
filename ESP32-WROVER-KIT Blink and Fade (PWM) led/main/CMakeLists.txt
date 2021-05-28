# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

#FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

#idf_component_register(SRCS ${app_sources})

set(SOURCES "main.c")
idf_component_register(SRCS "main.c" "timeInterrupt.c" "gpios.c"
                    INCLUDE_DIRS  "Headers")