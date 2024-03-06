cmake_minimum_required(VERSION 3.22)
project(ex4-shaderUniforms)

find_package(glfw3 CONFIG REQUIRED)

file(GLOB SRC_FILES *.cpp ../Utils/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC 
  ..
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC RenderLib)
