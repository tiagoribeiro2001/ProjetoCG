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
CMAKE_SOURCE_DIR = "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build"

# Include any dependencies generated for this target.
include CMakeFiles/matricesLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/matricesLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matricesLib.dir/flags.make

CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.o: CMakeFiles/matricesLib.dir/flags.make
CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.o: ../src/Matrices/matrices.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/Matrices/matrices.cpp"

CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/Matrices/matrices.cpp" > CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.i

CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/Matrices/matrices.cpp" -o CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.s

# Object files for target matricesLib
matricesLib_OBJECTS = \
"CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.o"

# External object files for target matricesLib
matricesLib_EXTERNAL_OBJECTS =

libmatricesLib.a: CMakeFiles/matricesLib.dir/src/Matrices/matrices.cpp.o
libmatricesLib.a: CMakeFiles/matricesLib.dir/build.make
libmatricesLib.a: CMakeFiles/matricesLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmatricesLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/matricesLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matricesLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matricesLib.dir/build: libmatricesLib.a

.PHONY : CMakeFiles/matricesLib.dir/build

CMakeFiles/matricesLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matricesLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matricesLib.dir/clean

CMakeFiles/matricesLib.dir/depend:
	cd "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles/matricesLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/matricesLib.dir/depend

