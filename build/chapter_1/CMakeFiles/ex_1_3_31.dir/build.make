# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/cn/learn/Algorithms-Fourth-Edition-Cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build

# Include any dependencies generated for this target.
include chapter_1/CMakeFiles/ex_1_3_31.dir/depend.make

# Include the progress variables for this target.
include chapter_1/CMakeFiles/ex_1_3_31.dir/progress.make

# Include the compile flags for this target's objects.
include chapter_1/CMakeFiles/ex_1_3_31.dir/flags.make

chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o: chapter_1/CMakeFiles/ex_1_3_31.dir/flags.make
chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o: ../chapter_1/exercise/ex_1_3_31.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o"
	cd /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o -c /home/cn/learn/Algorithms-Fourth-Edition-Cpp/chapter_1/exercise/ex_1_3_31.cpp

chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.i"
	cd /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cn/learn/Algorithms-Fourth-Edition-Cpp/chapter_1/exercise/ex_1_3_31.cpp > CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.i

chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.s"
	cd /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cn/learn/Algorithms-Fourth-Edition-Cpp/chapter_1/exercise/ex_1_3_31.cpp -o CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.s

chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.requires:

.PHONY : chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.requires

chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.provides: chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.requires
	$(MAKE) -f chapter_1/CMakeFiles/ex_1_3_31.dir/build.make chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.provides.build
.PHONY : chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.provides

chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.provides.build: chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o


# Object files for target ex_1_3_31
ex_1_3_31_OBJECTS = \
"CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o"

# External object files for target ex_1_3_31
ex_1_3_31_EXTERNAL_OBJECTS =

../bin/ex_1_3_31: chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o
../bin/ex_1_3_31: chapter_1/CMakeFiles/ex_1_3_31.dir/build.make
../bin/ex_1_3_31: chapter_1/CMakeFiles/ex_1_3_31.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/ex_1_3_31"
	cd /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex_1_3_31.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter_1/CMakeFiles/ex_1_3_31.dir/build: ../bin/ex_1_3_31

.PHONY : chapter_1/CMakeFiles/ex_1_3_31.dir/build

chapter_1/CMakeFiles/ex_1_3_31.dir/requires: chapter_1/CMakeFiles/ex_1_3_31.dir/exercise/ex_1_3_31.cpp.o.requires

.PHONY : chapter_1/CMakeFiles/ex_1_3_31.dir/requires

chapter_1/CMakeFiles/ex_1_3_31.dir/clean:
	cd /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1 && $(CMAKE_COMMAND) -P CMakeFiles/ex_1_3_31.dir/cmake_clean.cmake
.PHONY : chapter_1/CMakeFiles/ex_1_3_31.dir/clean

chapter_1/CMakeFiles/ex_1_3_31.dir/depend:
	cd /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cn/learn/Algorithms-Fourth-Edition-Cpp /home/cn/learn/Algorithms-Fourth-Edition-Cpp/chapter_1 /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1 /home/cn/learn/Algorithms-Fourth-Edition-Cpp/build/chapter_1/CMakeFiles/ex_1_3_31.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chapter_1/CMakeFiles/ex_1_3_31.dir/depend
