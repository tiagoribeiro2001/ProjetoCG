# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/tiago/Documents/CLion-2019.3.3/clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tiago/Documents/CLion-2019.3.3/clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/generatorLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generatorLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generatorLib.dir/flags.make

CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.o: CMakeFiles/generatorLib.dir/flags.make
CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.o: ../src/Generator/vertices.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Generator/vertices.cpp"

CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Generator/vertices.cpp" > CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.i

CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Generator/vertices.cpp" -o CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.s

# Object files for target generatorLib
generatorLib_OBJECTS = \
"CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.o"

# External object files for target generatorLib
generatorLib_EXTERNAL_OBJECTS =

libgeneratorLib.a: CMakeFiles/generatorLib.dir/src/Generator/vertices.cpp.o
libgeneratorLib.a: CMakeFiles/generatorLib.dir/build.make
libgeneratorLib.a: CMakeFiles/generatorLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgeneratorLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/generatorLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generatorLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generatorLib.dir/build: libgeneratorLib.a

.PHONY : CMakeFiles/generatorLib.dir/build

CMakeFiles/generatorLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generatorLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generatorLib.dir/clean

CMakeFiles/generatorLib.dir/depend:
	cd "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles/generatorLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/generatorLib.dir/depend

