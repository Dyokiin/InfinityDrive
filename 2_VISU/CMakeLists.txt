cmake_minimum_required(VERSION 3.8)

project(VISU)
add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(Camera)
target_include_directories(Camera PUBLIC "Camera/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Camera)

add_subdirectory(Shaders)
target_include_directories(Shaders PUBLIC "Shaders/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Shaders)

add_subdirectory(Texture)
target_include_directories(Texture PUBLIC "Texture/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Texture)

add_subdirectory(Scene)
target_include_directories(Scene PUBLIC "Scene/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Scene)