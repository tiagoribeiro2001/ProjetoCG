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
include CMakeFiles/Lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lib.dir/flags.make

CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.o: CMakeFiles/Lib.dir/flags.make
CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.o: ../src/tinyXML/tinystr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinystr.cpp"

CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinystr.cpp" > CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.i

CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinystr.cpp" -o CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.s

CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.o: CMakeFiles/Lib.dir/flags.make
CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.o: ../src/tinyXML/tinyxml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxml.cpp"

CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxml.cpp" > CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.i

CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxml.cpp" -o CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.s

CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.o: CMakeFiles/Lib.dir/flags.make
CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.o: ../src/tinyXML/tinyxmlerror.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxmlerror.cpp"

CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxmlerror.cpp" > CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.i

CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxmlerror.cpp" -o CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.s

CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.o: CMakeFiles/Lib.dir/flags.make
CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.o: ../src/tinyXML/tinyxmlparser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.o -c "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxmlparser.cpp"

CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxmlparser.cpp" > CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.i

CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/src/tinyXML/tinyxmlparser.cpp" -o CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.s

# Object files for target Lib
Lib_OBJECTS = \
"CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.o" \
"CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.o" \
"CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.o" \
"CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.o"

# External object files for target Lib
Lib_EXTERNAL_OBJECTS =

libLib.a: CMakeFiles/Lib.dir/src/tinyXML/tinystr.cpp.o
libLib.a: CMakeFiles/Lib.dir/src/tinyXML/tinyxml.cpp.o
libLib.a: CMakeFiles/Lib.dir/src/tinyXML/tinyxmlerror.cpp.o
libLib.a: CMakeFiles/Lib.dir/src/tinyXML/tinyxmlparser.cpp.o
libLib.a: CMakeFiles/Lib.dir/build.make
libLib.a: CMakeFiles/Lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lib.dir/build: libLib.a

.PHONY : CMakeFiles/Lib.dir/build

CMakeFiles/Lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lib.dir/clean

CMakeFiles/Lib.dir/depend:
	cd "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build" "/home/tiago/Desktop/Universidade/3º Ano/2º Semestre/CG/ProjetoCG/Fase3/build/CMakeFiles/Lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lib.dir/depend

