# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/andre/cmake-3.21.5/bin/cmake

# The command to remove a file.
RM = /home/andre/cmake-3.21.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/teste.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/teste.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/teste.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/teste.dir/flags.make

CMakeFiles/teste.dir/main.c.o: CMakeFiles/teste.dir/flags.make
CMakeFiles/teste.dir/main.c.o: ../main.c
CMakeFiles/teste.dir/main.c.o: CMakeFiles/teste.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/teste.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/teste.dir/main.c.o -MF CMakeFiles/teste.dir/main.c.o.d -o CMakeFiles/teste.dir/main.c.o -c "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/main.c"

CMakeFiles/teste.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/teste.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/main.c" > CMakeFiles/teste.dir/main.c.i

CMakeFiles/teste.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/teste.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/main.c" -o CMakeFiles/teste.dir/main.c.s

# Object files for target teste
teste_OBJECTS = \
"CMakeFiles/teste.dir/main.c.o"

# External object files for target teste
teste_EXTERNAL_OBJECTS =

teste: CMakeFiles/teste.dir/main.c.o
teste: CMakeFiles/teste.dir/build.make
teste: CMakeFiles/teste.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable teste"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/teste.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/teste.dir/build: teste
.PHONY : CMakeFiles/teste.dir/build

CMakeFiles/teste.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/teste.dir/cmake_clean.cmake
.PHONY : CMakeFiles/teste.dir/clean

CMakeFiles/teste.dir/depend:
	cd "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste" "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste" "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug" "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug" "/mnt/c/Users/andre/OneDrive/Área de Trabalho/dev/MCTA001-17/teste/cmake-build-debug/CMakeFiles/teste.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/teste.dir/depend

