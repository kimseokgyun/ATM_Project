# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kim/Bear-Robotics/ATMProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kim/Bear-Robotics/ATMProject/build

# Include any dependencies generated for this target.
include CMakeFiles/ATMProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ATMProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ATMProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ATMProject.dir/flags.make

CMakeFiles/ATMProject.dir/src/main.cpp.o: CMakeFiles/ATMProject.dir/flags.make
CMakeFiles/ATMProject.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/ATMProject.dir/src/main.cpp.o: CMakeFiles/ATMProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kim/Bear-Robotics/ATMProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ATMProject.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ATMProject.dir/src/main.cpp.o -MF CMakeFiles/ATMProject.dir/src/main.cpp.o.d -o CMakeFiles/ATMProject.dir/src/main.cpp.o -c /home/kim/Bear-Robotics/ATMProject/src/main.cpp

CMakeFiles/ATMProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ATMProject.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kim/Bear-Robotics/ATMProject/src/main.cpp > CMakeFiles/ATMProject.dir/src/main.cpp.i

CMakeFiles/ATMProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ATMProject.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kim/Bear-Robotics/ATMProject/src/main.cpp -o CMakeFiles/ATMProject.dir/src/main.cpp.s

# Object files for target ATMProject
ATMProject_OBJECTS = \
"CMakeFiles/ATMProject.dir/src/main.cpp.o"

# External object files for target ATMProject
ATMProject_EXTERNAL_OBJECTS =

ATMProject: CMakeFiles/ATMProject.dir/src/main.cpp.o
ATMProject: CMakeFiles/ATMProject.dir/build.make
ATMProject: /usr/lib/x86_64-linux-gnu/libyaml-cpp.so.0.7.0
ATMProject: CMakeFiles/ATMProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kim/Bear-Robotics/ATMProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ATMProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ATMProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ATMProject.dir/build: ATMProject
.PHONY : CMakeFiles/ATMProject.dir/build

CMakeFiles/ATMProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ATMProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ATMProject.dir/clean

CMakeFiles/ATMProject.dir/depend:
	cd /home/kim/Bear-Robotics/ATMProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kim/Bear-Robotics/ATMProject /home/kim/Bear-Robotics/ATMProject /home/kim/Bear-Robotics/ATMProject/build /home/kim/Bear-Robotics/ATMProject/build /home/kim/Bear-Robotics/ATMProject/build/CMakeFiles/ATMProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ATMProject.dir/depend

