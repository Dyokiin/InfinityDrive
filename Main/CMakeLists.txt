cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(Main)

find_package(SDL2 REQUIRED)

# collect all cpp files (sometimes considered as bad practice)
file(GLOB_RECURSE src_files_list src/*.cpp)

# files to compile
add_executable(Main main.cpp)

# lib include path
target_include_directories(Main PRIVATE Libmacrun)
target_include_directories(Main PRIVATE "${SDL2_INCLUDE_DIRS}")

# specify the library lib path
target_link_libraries(Main PRIVATE Libmacrun)
target_link_libraries(Main PRIVATE ${SDL2_LIBRARIES})

# compilation flags
target_compile_features(Main PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(Main PRIVATE -Wall -O2)   # specify some compilation flags
