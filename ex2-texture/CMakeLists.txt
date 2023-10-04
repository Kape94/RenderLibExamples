cmake_minimum_required(VERSION 3.22)
project(ex2-texture)

find_package(glfw3 CONFIG REQUIRED)

file(GLOB SRC_FILES *.cpp ../Utils/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${PROJECT_SOURCE_DIR}/blue-light-style.jpg
                   ${PROJECT_BINARY_DIR}
                   COMMENT "Copying resources")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   ${PROJECT_SOURCE_DIR}/solar-flare.jpg
                   ${PROJECT_BINARY_DIR}
                   COMMENT "Copying resources")

target_include_directories(${PROJECT_NAME} PUBLIC 
  ..
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC RenderLib)
