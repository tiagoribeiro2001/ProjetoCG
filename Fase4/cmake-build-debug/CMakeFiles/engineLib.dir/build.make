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
include CMakeFiles/engineLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engineLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engineLib.dir/flags.make

CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.o: CMakeFiles/engineLib.dir/flags.make
CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.o: ../src/Engine/drawFunctions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Engine/drawFunctions.cpp"

CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Engine/drawFunctions.cpp" > CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.i

CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Engine/drawFunctions.cpp" -o CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.s

CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.o: CMakeFiles/engineLib.dir/flags.make
CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.o: ../src/Engine/catmullRom.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Engine/catmullRom.cpp"

CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Engine/catmullRom.cpp" > CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.i

CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/src/Engine/catmullRom.cpp" -o CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.s

# Object files for target engineLib
engineLib_OBJECTS = \
"CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.o" \
"CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.o"

# External object files for target engineLib
engineLib_EXTERNAL_OBJECTS =

libengineLib.a: CMakeFiles/engineLib.dir/src/Engine/drawFunctions.cpp.o
libengineLib.a: CMakeFiles/engineLib.dir/src/Engine/catmullRom.cpp.o
libengineLib.a: CMakeFiles/engineLib.dir/build.make
libengineLib.a: CMakeFiles/engineLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libengineLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/engineLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engineLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engineLib.dir/build: libengineLib.a

.PHONY : CMakeFiles/engineLib.dir/build

CMakeFiles/engineLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engineLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engineLib.dir/clean

CMakeFiles/engineLib.dir/depend:
	cd "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase4/cmake-build-debug/CMakeFiles/engineLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/engineLib.dir/depend

