cmake_minimum_required(VERSION 3.8)

INCLUDE(FindPkgConfig)

project(InfinityDrive)
add_executable(${PROJECT_NAME} 4_MAIN/main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

# Enable many good warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O2 -w)
endif()

# Set the folder where the executable is created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/)

# Add all the files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS 4_MAIN/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE MAIN)


# --- Include libs
add_subdirectory(3_EXT_INCLUDES)
add_library(3_EXT_INCLUDES INTERFACE)
target_include_directories(${PROJECT_NAME} PUBLIC "3_EXT_INCLUDES/include")
target_link_libraries(${PROJECT_NAME} PUBLIC EXT_INCLUDES)

add_subdirectory(2_VISU)
add_library(2_VISU_INCLUDES INTERFACE)
target_include_directories(${PROJECT_NAME} PUBLIC "2_VISU/*/include")
target_link_libraries(${PROJECT_NAME} PUBLIC VISU)

add_subdirectory(1_CORE)
add_library(1_CORE_INCLUDES INTERFACE)
target_include_directories(${PROJECT_NAME} PUBLIC "1_CORE/*/include")
target_link_libraries(${PROJECT_NAME} PUBLIC CORE)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(OpenGL REQUIRED gl)
pkg_check_modules(GLEW REQUIRED glew)
pkg_check_modules(SDL_ttf REQUIRED SDL_ttf)

target_include_directories(InfinityDrive PRIVATE "${SDL2_INCLUDE_DIRS}")
target_include_directories(InfinityDrive PRIVATE "${OpenGL_INCLUDE_DIRS}")
target_include_directories(InfinityDrive PRIVATE "${GLEW_INCLUDE_DIRS}")
target_include_directories(InfinityDrive PRIVATE libs/assimp-3.1.1/include/)
target_include_directories(InfinityDrive PRIVATE "${SDL_ttf_INCLUDE_DIRS}")

target_link_libraries(InfinityDrive PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(InfinityDrive PRIVATE ${OpenGL_LIBRARIES})
target_link_libraries(InfinityDrive PRIVATE ${GLEW_LIBRARIES})
target_link_libraries(InfinityDrive PRIVATE assimp)
target_link_libraries(InfinityDrive PRIVATE ${SDL_ttf_LIBRARIES})
