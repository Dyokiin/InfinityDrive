cmake_minimum_required(VERSION 3.13)

INCLUDE(FindPkgConfig)


# give a name to the project
project(IMACRun)

# display VERBOSE messages : cmake --log-level=VERBOSE ..

# specify the system
message(VERBOSE "CMAKE_VERSION           : " ${CMAKE_VERSION})
message(VERBOSE "CMAKE_SYSTEM_NAME       : " ${CMAKE_SYSTEM_NAME})
message(VERBOSE "CMAKE_SYSTEM            : " ${CMAKE_SYSTEM})
message(VERBOSE "CMAKE_SYSTEM_PROCESSOR  : " ${CMAKE_SYSTEM_PROCESSOR} "\n")

# specify the directories
message(VERBOSE "CMAKE_BINARY_DIR        : " ${CMAKE_BINARY_DIR})
message(VERBOSE "CMAKE_SOURCE_DIR        : " ${CMAKE_SOURCE_DIR})
message(VERBOSE "CMAKE_HOME_DIRECTORY    : " ${CMAKE_HOME_DIRECTORY})
message(VERBOSE "PROJECT_BINARY_DIR      : " ${PROJECT_BINARY_DIR})
message(VERBOSE "PROJECT_SOURCE_DIR      : " ${PROJECT_SOURCE_DIR} "\n")

# compile flags
message(VERBOSE "CMAKE_CXX_FLAGS         : " ${CMAKE_CXX_FLAG})
message(VERBOSE "CMAKE_CXX_FLAGS_DEBUG   : " ${CMAKE_CXX_FLAGS_DEBUG})
message(VERBOSE "CMAKE_CXX_FLAGS_RELEASE : " ${CMAKE_CXX_FLAGS_RELEASE})
message(VERBOSE "CMAKE_CXX_COMPILER      : " ${CMAKE_CXX_COMPILER} "\n")

# (optional) add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# (optional) put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)



message(STATUS "Lib cmake part ..." )
add_subdirectory(Lib INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/Lib/include)

# add myCode2
message(STATUS "Libmacrun cmake part ..." )
add_subdirectory(Libmacrun)
include_directories(${CMAKE_SOURCE_DIR}/Libmacrun/include)

# collect all cpp files (sometimes considered as bad practice)
file(GLOB_RECURSE src_files_list src/*.cpp)

# files to compile
add_executable(IMACRun main.cpp)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
#pkg_check_modules(SDL2_MIX REQUIRED SDL2_mixer)

include_directories(${SDL2_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS})
    #    ${SDL2_MIX_INCLUDE_DIRS}

link_directories (${SDL2_LIBRARY_DIRS}
    ${SDL2_TTF_LIBRARY_DIRS})
    #    ${SDL2_MIX_LIBRARY_DIRS}

# lib include path
target_include_directories(IMACRun PRIVATE Libmacrun)
target_include_directories(IMACRun PRIVATE Lib)
target_include_directories(IMACRun PRIVATE "${SDL2_INCLUDE_DIRS}")
target_include_directories(IMACRun PRIVATE "${SDL2_TTF_INCLUDE_DIRS}")

# specify the library lib path
target_link_libraries(IMACRun PRIVATE Libmacrun)
target_link_libraries(IMACRun PRIVATE Lib)
target_link_libraries(IMACRun PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(IMACRun PRIVATE ${SDL2_TTF_LIBRARIES})

# compilation flags
target_compile_features(IMACRun PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(IMACRun PRIVATE -Wall -O2)   # specify some compilation flags
