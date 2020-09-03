set(MODULE_NAME util)


## Set up 3rdParty library ----------------------------------------------------

add_library(${MODULE_NAME}
  Shader.cpp
  Shader.h
  IOTools.h
)

target_include_directories(${MODULE_NAME}
  PUBLIC
    ${GL3W_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${MODULE_NAME}
	PRIVATE
	3rdParty
)


