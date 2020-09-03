set(MODULE_NAME 3rdParty)


## Set up 3rdParty library ----------------------------------------------------

add_library(${MODULE_NAME}
  filesystem.hpp
  glad.h
  glad.c
  stb_image.cpp
  stb_image.h
)

target_include_directories(${MODULE_NAME}
  PUBLIC
    ${GL3W_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)



