# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/nikki/CLionProjects/MobilityModelCLI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MobilityModelCLI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MobilityModelCLI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MobilityModelCLI.dir/flags.make

CMakeFiles/MobilityModelCLI.dir/main.cpp.o: CMakeFiles/MobilityModelCLI.dir/flags.make
CMakeFiles/MobilityModelCLI.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MobilityModelCLI.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MobilityModelCLI.dir/main.cpp.o -c /home/nikki/CLionProjects/MobilityModelCLI/main.cpp

CMakeFiles/MobilityModelCLI.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MobilityModelCLI.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikki/CLionProjects/MobilityModelCLI/main.cpp > CMakeFiles/MobilityModelCLI.dir/main.cpp.i

CMakeFiles/MobilityModelCLI.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MobilityModelCLI.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikki/CLionProjects/MobilityModelCLI/main.cpp -o CMakeFiles/MobilityModelCLI.dir/main.cpp.s

CMakeFiles/MobilityModelCLI.dir/node.cpp.o: CMakeFiles/MobilityModelCLI.dir/flags.make
CMakeFiles/MobilityModelCLI.dir/node.cpp.o: ../node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MobilityModelCLI.dir/node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MobilityModelCLI.dir/node.cpp.o -c /home/nikki/CLionProjects/MobilityModelCLI/node.cpp

CMakeFiles/MobilityModelCLI.dir/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MobilityModelCLI.dir/node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikki/CLionProjects/MobilityModelCLI/node.cpp > CMakeFiles/MobilityModelCLI.dir/node.cpp.i

CMakeFiles/MobilityModelCLI.dir/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MobilityModelCLI.dir/node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikki/CLionProjects/MobilityModelCLI/node.cpp -o CMakeFiles/MobilityModelCLI.dir/node.cpp.s

CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.o: CMakeFiles/MobilityModelCLI.dir/flags.make
CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.o: ../random_walk_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.o -c /home/nikki/CLionProjects/MobilityModelCLI/random_walk_node.cpp

CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikki/CLionProjects/MobilityModelCLI/random_walk_node.cpp > CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.i

CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikki/CLionProjects/MobilityModelCLI/random_walk_node.cpp -o CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.s

CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.o: CMakeFiles/MobilityModelCLI.dir/flags.make
CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.o: ../random_direction_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.o -c /home/nikki/CLionProjects/MobilityModelCLI/random_direction_node.cpp

CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikki/CLionProjects/MobilityModelCLI/random_direction_node.cpp > CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.i

CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikki/CLionProjects/MobilityModelCLI/random_direction_node.cpp -o CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.s

CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.o: CMakeFiles/MobilityModelCLI.dir/flags.make
CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.o: ../random_waypoint_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.o -c /home/nikki/CLionProjects/MobilityModelCLI/random_waypoint_node.cpp

CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikki/CLionProjects/MobilityModelCLI/random_waypoint_node.cpp > CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.i

CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikki/CLionProjects/MobilityModelCLI/random_waypoint_node.cpp -o CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.s

CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.o: CMakeFiles/MobilityModelCLI.dir/flags.make
CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.o: ../gauss_markov_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.o -c /home/nikki/CLionProjects/MobilityModelCLI/gauss_markov_node.cpp

CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nikki/CLionProjects/MobilityModelCLI/gauss_markov_node.cpp > CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.i

CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nikki/CLionProjects/MobilityModelCLI/gauss_markov_node.cpp -o CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.s

# Object files for target MobilityModelCLI
MobilityModelCLI_OBJECTS = \
"CMakeFiles/MobilityModelCLI.dir/main.cpp.o" \
"CMakeFiles/MobilityModelCLI.dir/node.cpp.o" \
"CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.o" \
"CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.o" \
"CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.o" \
"CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.o"

# External object files for target MobilityModelCLI
MobilityModelCLI_EXTERNAL_OBJECTS =

MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/main.cpp.o
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/node.cpp.o
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/random_walk_node.cpp.o
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/random_direction_node.cpp.o
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/random_waypoint_node.cpp.o
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/gauss_markov_node.cpp.o
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/build.make
MobilityModelCLI: CMakeFiles/MobilityModelCLI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable MobilityModelCLI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MobilityModelCLI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MobilityModelCLI.dir/build: MobilityModelCLI

.PHONY : CMakeFiles/MobilityModelCLI.dir/build

CMakeFiles/MobilityModelCLI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MobilityModelCLI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MobilityModelCLI.dir/clean

CMakeFiles/MobilityModelCLI.dir/depend:
	cd /home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikki/CLionProjects/MobilityModelCLI /home/nikki/CLionProjects/MobilityModelCLI /home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug /home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug /home/nikki/CLionProjects/MobilityModelCLI/cmake-build-debug/CMakeFiles/MobilityModelCLI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MobilityModelCLI.dir/depend

