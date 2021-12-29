cmake_minimum_required(VERSION 3.8)

project(CORE)
add_library(${PROJECT_NAME} INTERFACE)

add_subdirectory(Box)
target_include_directories(Box PUBLIC "Box/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Box)

add_subdirectory(File)
target_include_directories(File PUBLIC "File/include")
target_link_libraries(${PROJECT_NAME} INTERFACE File)

add_subdirectory(Control)
target_include_directories(Control PUBLIC "Control/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Control)

add_subdirectory(Menu)
target_include_directories(Menu PUBLIC "Menu/include")
target_link_libraries(${PROJECT_NAME} INTERFACE Menu)