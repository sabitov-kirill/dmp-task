# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/ne1mnn/.cache/JetBrains/RemoteDev/dist/69f6ce9329a28_CLion-233.11799.171/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/ne1mnn/.cache/JetBrains/RemoteDev/dist/69f6ce9329a28_CLion-233.11799.171/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ne1mnn/code/dmp-task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ne1mnn/code/dmp-task/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dummy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dummy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dummy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dummy.dir/flags.make

CMakeFiles/dummy.dir/src/display_stat.c.o: CMakeFiles/dummy.dir/flags.make
CMakeFiles/dummy.dir/src/display_stat.c.o: /home/ne1mnn/code/dmp-task/src/display_stat.c
CMakeFiles/dummy.dir/src/display_stat.c.o: CMakeFiles/dummy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ne1mnn/code/dmp-task/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dummy.dir/src/display_stat.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/dummy.dir/src/display_stat.c.o -MF CMakeFiles/dummy.dir/src/display_stat.c.o.d -o CMakeFiles/dummy.dir/src/display_stat.c.o -c /home/ne1mnn/code/dmp-task/src/display_stat.c

CMakeFiles/dummy.dir/src/display_stat.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/dummy.dir/src/display_stat.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ne1mnn/code/dmp-task/src/display_stat.c > CMakeFiles/dummy.dir/src/display_stat.c.i

CMakeFiles/dummy.dir/src/display_stat.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/dummy.dir/src/display_stat.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ne1mnn/code/dmp-task/src/display_stat.c -o CMakeFiles/dummy.dir/src/display_stat.c.s

CMakeFiles/dummy.dir/src/dmp.c.o: CMakeFiles/dummy.dir/flags.make
CMakeFiles/dummy.dir/src/dmp.c.o: /home/ne1mnn/code/dmp-task/src/dmp.c
CMakeFiles/dummy.dir/src/dmp.c.o: CMakeFiles/dummy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ne1mnn/code/dmp-task/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dummy.dir/src/dmp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/dummy.dir/src/dmp.c.o -MF CMakeFiles/dummy.dir/src/dmp.c.o.d -o CMakeFiles/dummy.dir/src/dmp.c.o -c /home/ne1mnn/code/dmp-task/src/dmp.c

CMakeFiles/dummy.dir/src/dmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/dummy.dir/src/dmp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ne1mnn/code/dmp-task/src/dmp.c > CMakeFiles/dummy.dir/src/dmp.c.i

CMakeFiles/dummy.dir/src/dmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/dummy.dir/src/dmp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ne1mnn/code/dmp-task/src/dmp.c -o CMakeFiles/dummy.dir/src/dmp.c.s

CMakeFiles/dummy.dir/src/entrypoint.c.o: CMakeFiles/dummy.dir/flags.make
CMakeFiles/dummy.dir/src/entrypoint.c.o: /home/ne1mnn/code/dmp-task/src/entrypoint.c
CMakeFiles/dummy.dir/src/entrypoint.c.o: CMakeFiles/dummy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ne1mnn/code/dmp-task/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/dummy.dir/src/entrypoint.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/dummy.dir/src/entrypoint.c.o -MF CMakeFiles/dummy.dir/src/entrypoint.c.o.d -o CMakeFiles/dummy.dir/src/entrypoint.c.o -c /home/ne1mnn/code/dmp-task/src/entrypoint.c

CMakeFiles/dummy.dir/src/entrypoint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/dummy.dir/src/entrypoint.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ne1mnn/code/dmp-task/src/entrypoint.c > CMakeFiles/dummy.dir/src/entrypoint.c.i

CMakeFiles/dummy.dir/src/entrypoint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/dummy.dir/src/entrypoint.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ne1mnn/code/dmp-task/src/entrypoint.c -o CMakeFiles/dummy.dir/src/entrypoint.c.s

# Object files for target dummy
dummy_OBJECTS = \
"CMakeFiles/dummy.dir/src/display_stat.c.o" \
"CMakeFiles/dummy.dir/src/dmp.c.o" \
"CMakeFiles/dummy.dir/src/entrypoint.c.o"

# External object files for target dummy
dummy_EXTERNAL_OBJECTS =

libdummy.a: CMakeFiles/dummy.dir/src/display_stat.c.o
libdummy.a: CMakeFiles/dummy.dir/src/dmp.c.o
libdummy.a: CMakeFiles/dummy.dir/src/entrypoint.c.o
libdummy.a: CMakeFiles/dummy.dir/build.make
libdummy.a: CMakeFiles/dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ne1mnn/code/dmp-task/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libdummy.a"
	$(CMAKE_COMMAND) -P CMakeFiles/dummy.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dummy.dir/build: libdummy.a
.PHONY : CMakeFiles/dummy.dir/build

CMakeFiles/dummy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dummy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dummy.dir/clean

CMakeFiles/dummy.dir/depend:
	cd /home/ne1mnn/code/dmp-task/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ne1mnn/code/dmp-task /home/ne1mnn/code/dmp-task /home/ne1mnn/code/dmp-task/cmake-build-debug /home/ne1mnn/code/dmp-task/cmake-build-debug /home/ne1mnn/code/dmp-task/cmake-build-debug/CMakeFiles/dummy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dummy.dir/depend
