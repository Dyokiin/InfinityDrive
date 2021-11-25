cmake_minimum_required(VERSION 3.8)

project(VISU)
add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(Camera)
target_include_directories(Camera PUBLIC "Camera/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Camera)

add_subdirectory(Mesh)
target_include_directories(Mesh PUBLIC "Mesh/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Mesh)

add_subdirectory(Object)
target_include_directories(Object PUBLIC "Object/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Object)

add_subdirectory(Shaders)
target_include_directories(Shaders PUBLIC "Shaders/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Shaders)

add_subdirectory(Texture)
target_include_directories(Texture PUBLIC "Texture/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Texture)