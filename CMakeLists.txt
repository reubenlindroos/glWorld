# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("glWorld")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#############################
# DEPENDENCIES
#############################

## OpenGL
find_package(OpenGL REQUIRED)

## GL3W (Modern GL Extension Wrangler)
#TODO: get a FindGL3W.cmake
set(GL3W_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/3rdParty/gl3w
  CACHE PATH "GL3W ROOT DIR")

set(GL3W_FILES
  ${GL3W_INCLUDE_DIR}/GL/gl3w.c
  ${GL3W_INCLUDE_DIR}/GL/gl3w.h
  ${GL3W_INCLUDE_DIR}/GL/glcorearb.h
)
include_directories(${GL3W_INCLUDE_DIR})

## GLFW
find_package(glfw3 3.3 REQUIRED)

##################################
# INTERNAL DEPENCENCIES
##################################
add_subdirectory("3rdParty")
add_subdirectory ("util")



#################################
# EXECUTABLES
#################################
add_subdirectory("src/part1")
add_subdirectory("src/part2")
add_subdirectory("src/part3")