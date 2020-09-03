set(MODULE_NAME part2)

file(GLOB sources "*.cpp")
file(GLOB headers "*.hpp")
list(APPEND files ${sources} ${headers})

add_executable(${MODULE_NAME}
  ${sources}
  ${headers}
)

set_target_properties(${MODULE_NAME} PROPERTIES
  FOLDER src
)
target_include_directories(${MODULE_NAME}
  PUBLIC
    ${GL3W_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${MODULE_NAME}
  PUBLIC
    3rdParty
    util
    glfw
)
