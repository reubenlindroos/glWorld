set(MODULE_NAME part3)

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

target_link_libraries(${MODULE_NAME}
  PUBLIC
    3rdParty
    util
    glfw
)

#install (TARGETS ${MODULE_NAME} DESTINATION bin)
