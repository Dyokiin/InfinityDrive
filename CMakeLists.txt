cmake_minimum_required(VERSION 3.8)

INCLUDE(FindPkgConfig)

project(VroomRun)
add_executable(${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

# Enable many good warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -O2 -w)
endif()

# Set the folder where the executable is created
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Add all the files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS MAIN/*)
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE MAIN)


# --- Include libs
add_subdirectory(EXT_INCLUDES)
target_include_directories(${PROJECT_NAME} PUBLIC "EXT_INCLUDES/include")
target_link_libraries(${PROJECT_NAME} PUBLIC EXT_INCLUDES)

add_subdirectory(VISU)
target_include_directories(${PROJECT_NAME} PUBLIC "VISU/*/include")
target_link_libraries(${PROJECT_NAME} PUBLIC VISU)

add_subdirectory(CORE)
target_include_directories(${PROJECT_NAME} PUBLIC "CORE/*/include")
target_link_libraries(${PROJECT_NAME} PUBLIC CORE)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(OpenGL REQUIRED gl)
pkg_check_modules(GLEW REQUIRED glew)

target_include_directories(VroomRun PRIVATE "${SDL2_INCLUDE_DIRS}")
target_include_directories(VroomRun PRIVATE "${SDL2_TTF_INCLUDE_DIRS}")
target_include_directories(VroomRun PRIVATE "${OpenGL_INCLUDE_DIRS}")
target_include_directories(VroomRun PRIVATE "${GLEW_INCLUDE_DIRS}")

target_link_libraries(VroomRun PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(VroomRun PRIVATE ${SDL2_TTF_LIBRARIES})
target_link_libraries(VroomRun PRIVATE ${OpenGL_LIBRARIES})
target_link_libraries(VroomRun PRIVATE ${GLEW_LIBRARIES})