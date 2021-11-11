cmake_minimum_required(VERSION 3.13)


project(LIBMACRun)

# add myLib
message(STATUS "HitBox cmake part ..." )
add_subdirectory(HitBox)
include_directories(${CMAKE_SOURCE_DIR}/HitBox/include) # important : other projects called by this cmake will know this include directory

message(STATUS "Program cmake part ..." )
add_subdirectory(Program)
include_directories(${CMAKE_SOURCE_DIR}/Program/include) # important : other projects called by this cmake will know this include directory

message(STATUS "SDLWindow cmake part ..." )
add_subdirectory(SDLWindow)
include_directories(${CMAKE_SOURCE_DIR}/SDLWindow/include) # important : other projects called by this cmake will know this include directory