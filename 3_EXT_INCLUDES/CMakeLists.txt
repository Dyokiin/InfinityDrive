cmake_minimum_required(VERSION 3.8)

project(EXT_INCLUDES)
add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(Window)
target_include_directories(Window PUBLIC "Window/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Window)
