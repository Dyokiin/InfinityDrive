# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/theo/VroomRun

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/theo/VroomRun/build

# Include any dependencies generated for this target.
include INTERFACE/CMakeFiles/Lib.dir/depend.make

# Include the progress variables for this target.
include INTERFACE/CMakeFiles/Lib.dir/progress.make

# Include the compile flags for this target's objects.
include INTERFACE/CMakeFiles/Lib.dir/flags.make

INTERFACE/CMakeFiles/Lib.dir/src/Image.cpp.o: INTERFACE/CMakeFiles/Lib.dir/flags.make
INTERFACE/CMakeFiles/Lib.dir/src/Image.cpp.o: ../Lib/src/Image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/VroomRun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object INTERFACE/CMakeFiles/Lib.dir/src/Image.cpp.o"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/Image.cpp.o -c /home/theo/VroomRun/Lib/src/Image.cpp

INTERFACE/CMakeFiles/Lib.dir/src/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/Image.cpp.i"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/VroomRun/Lib/src/Image.cpp > CMakeFiles/Lib.dir/src/Image.cpp.i

INTERFACE/CMakeFiles/Lib.dir/src/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/Image.cpp.s"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/VroomRun/Lib/src/Image.cpp -o CMakeFiles/Lib.dir/src/Image.cpp.s

INTERFACE/CMakeFiles/Lib.dir/src/Program.cpp.o: INTERFACE/CMakeFiles/Lib.dir/flags.make
INTERFACE/CMakeFiles/Lib.dir/src/Program.cpp.o: ../Lib/src/Program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/VroomRun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object INTERFACE/CMakeFiles/Lib.dir/src/Program.cpp.o"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/Program.cpp.o -c /home/theo/VroomRun/Lib/src/Program.cpp

INTERFACE/CMakeFiles/Lib.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/Program.cpp.i"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/VroomRun/Lib/src/Program.cpp > CMakeFiles/Lib.dir/src/Program.cpp.i

INTERFACE/CMakeFiles/Lib.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/Program.cpp.s"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/VroomRun/Lib/src/Program.cpp -o CMakeFiles/Lib.dir/src/Program.cpp.s

INTERFACE/CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.o: INTERFACE/CMakeFiles/Lib.dir/flags.make
INTERFACE/CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.o: ../Lib/src/SDLTtfManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/VroomRun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object INTERFACE/CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.o"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.o -c /home/theo/VroomRun/Lib/src/SDLTtfManager.cpp

INTERFACE/CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.i"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/VroomRun/Lib/src/SDLTtfManager.cpp > CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.i

INTERFACE/CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.s"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/VroomRun/Lib/src/SDLTtfManager.cpp -o CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.s

INTERFACE/CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.o: INTERFACE/CMakeFiles/Lib.dir/flags.make
INTERFACE/CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.o: ../Lib/src/SDLWindowManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/VroomRun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object INTERFACE/CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.o"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.o -c /home/theo/VroomRun/Lib/src/SDLWindowManager.cpp

INTERFACE/CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.i"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/VroomRun/Lib/src/SDLWindowManager.cpp > CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.i

INTERFACE/CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.s"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/VroomRun/Lib/src/SDLWindowManager.cpp -o CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.s

INTERFACE/CMakeFiles/Lib.dir/src/Shader.cpp.o: INTERFACE/CMakeFiles/Lib.dir/flags.make
INTERFACE/CMakeFiles/Lib.dir/src/Shader.cpp.o: ../Lib/src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/theo/VroomRun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object INTERFACE/CMakeFiles/Lib.dir/src/Shader.cpp.o"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/Shader.cpp.o -c /home/theo/VroomRun/Lib/src/Shader.cpp

INTERFACE/CMakeFiles/Lib.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/Shader.cpp.i"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/theo/VroomRun/Lib/src/Shader.cpp > CMakeFiles/Lib.dir/src/Shader.cpp.i

INTERFACE/CMakeFiles/Lib.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/Shader.cpp.s"
	cd /home/theo/VroomRun/build/INTERFACE && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/theo/VroomRun/Lib/src/Shader.cpp -o CMakeFiles/Lib.dir/src/Shader.cpp.s

# Object files for target Lib
Lib_OBJECTS = \
"CMakeFiles/Lib.dir/src/Image.cpp.o" \
"CMakeFiles/Lib.dir/src/Program.cpp.o" \
"CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.o" \
"CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.o" \
"CMakeFiles/Lib.dir/src/Shader.cpp.o"

# External object files for target Lib
Lib_EXTERNAL_OBJECTS =

INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/src/Image.cpp.o
INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/src/Program.cpp.o
INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/src/SDLTtfManager.cpp.o
INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/src/SDLWindowManager.cpp.o
INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/src/Shader.cpp.o
INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/build.make
INTERFACE/libLib.a: INTERFACE/CMakeFiles/Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/theo/VroomRun/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libLib.a"
	cd /home/theo/VroomRun/build/INTERFACE && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean_target.cmake
	cd /home/theo/VroomRun/build/INTERFACE && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
INTERFACE/CMakeFiles/Lib.dir/build: INTERFACE/libLib.a

.PHONY : INTERFACE/CMakeFiles/Lib.dir/build

INTERFACE/CMakeFiles/Lib.dir/clean:
	cd /home/theo/VroomRun/build/INTERFACE && $(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean.cmake
.PHONY : INTERFACE/CMakeFiles/Lib.dir/clean

INTERFACE/CMakeFiles/Lib.dir/depend:
	cd /home/theo/VroomRun/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/theo/VroomRun /home/theo/VroomRun/Lib /home/theo/VroomRun/build /home/theo/VroomRun/build/INTERFACE /home/theo/VroomRun/build/INTERFACE/CMakeFiles/Lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : INTERFACE/CMakeFiles/Lib.dir/depend

