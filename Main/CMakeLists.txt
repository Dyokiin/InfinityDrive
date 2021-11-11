cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(Main)

# include directory
#target_include_directories(Main PRIVATE "include")

find_package(SDL2 REQUIRED)
include_directories(${DSL2_INCLUDE_DIRS})

# file to compile and name of the executable
add_executable(Main main.cpp)

target_link_libraries(Main ${SDL2_LIBRARIES})

# compilation options
target_compile_features(Main PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(Main PRIVATE -Wall -O2)   # specify some compilation flags
