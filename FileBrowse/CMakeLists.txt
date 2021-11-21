cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(FileBrowse LANGUAGES C CXX)

# automatic get all files in a directory
file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files include/*.hpp)

# call the CMakeLists.txt to make the documentation (Doxygen)
find_package(Doxygen OPTIONAL_COMPONENTS QUIET)
if(DOXYGEN_FOUND)
	#add_subdirectory(doc)
else()
	message(WARNING "Doxygen not found, skip dococumentation")
endif()

# Instructions to compile a library (no main() inside)
# default STATIC ??
# SHARED to make a .so instead of a .a
# add_library(ganQ SHARED ${source_files} ${header_files})
add_library(FileBrowse ${source_files} ${header_files})

# compilation flags
target_compile_features(FileBrowse PRIVATE cxx_std_11) # use at least c++ 11
target_compile_options(FileBrowse PRIVATE -Wall -O2)   # specify some compilation flags

# include directory
target_include_directories(FileBrowse PRIVATE "include")

# install (optional, install a lib is not mandatory)
install(FILES ${header_files} DESTINATION /usr/local/include/FileBrowse)
install(TARGETS FileBrowse
        RUNTIME DESTINATION /usr/local/lib
        LIBRARY DESTINATION /usr/local/lib
        ARCHIVE DESTINATION /usr/local/lib)