include(AICxxProject)

add_executable(main main.cxx window.cxx vulkan_app.cxx)
target_link_libraries(main PRIVATE ${AICXX_OBJECTS_LIST} PUBLIC glfw)
