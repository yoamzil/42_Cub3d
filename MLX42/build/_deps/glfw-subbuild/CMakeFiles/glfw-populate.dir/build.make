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
CMAKE_COMMAND = /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/omakran/MLX42/build/_deps/glfw-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omakran/MLX42/build/_deps/glfw-subbuild

# Utility rule file for glfw-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/glfw-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/glfw-populate.dir/progress.make

CMakeFiles/glfw-populate: CMakeFiles/glfw-populate-complete

CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-install
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-mkdir
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-download
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-configure
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-build
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-install
CMakeFiles/glfw-populate-complete: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'glfw-populate'"
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E make_directory /Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles/glfw-populate-complete
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-done

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update:
.PHONY : glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-build: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'glfw-populate'"
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E echo_append
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-build

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-configure: glfw-populate-prefix/tmp/glfw-populate-cfgcmd.txt
glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-configure: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'glfw-populate'"
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E echo_append
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-configure

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-download: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-gitinfo.txt
glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-download: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'glfw-populate'"
	cd /Users/omakran/MLX42/build/_deps && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -P /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/tmp/glfw-populate-gitclone.cmake
	cd /Users/omakran/MLX42/build/_deps && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-download

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-install: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'glfw-populate'"
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E echo_append
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-install

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'glfw-populate'"
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -Dcfgdir= -P /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/tmp/glfw-populate-mkdirs.cmake
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-mkdir

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch-info.txt
glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'glfw-populate'"
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E echo_append
	/Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update:
.PHONY : glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-test: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'glfw-populate'"
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E echo_append
	cd /Users/omakran/MLX42/build/_deps/glfw-build && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-test

glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update: glfw-populate-prefix/tmp/glfw-populate-gitupdate.cmake
glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update-info.txt
glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'glfw-populate'"
	cd /Users/omakran/MLX42/build/_deps/glfw-src && /Users/omakran/.brew/Cellar/cmake/3.27.7/bin/cmake -Dcan_fetch=YES -P /Users/omakran/MLX42/build/_deps/glfw-subbuild/glfw-populate-prefix/tmp/glfw-populate-gitupdate.cmake

glfw-populate: CMakeFiles/glfw-populate
glfw-populate: CMakeFiles/glfw-populate-complete
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-build
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-configure
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-download
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-install
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-mkdir
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-patch
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-test
glfw-populate: glfw-populate-prefix/src/glfw-populate-stamp/glfw-populate-update
glfw-populate: CMakeFiles/glfw-populate.dir/build.make
.PHONY : glfw-populate

# Rule to build all files generated by this target.
CMakeFiles/glfw-populate.dir/build: glfw-populate
.PHONY : CMakeFiles/glfw-populate.dir/build

CMakeFiles/glfw-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/glfw-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/glfw-populate.dir/clean

CMakeFiles/glfw-populate.dir/depend:
	cd /Users/omakran/MLX42/build/_deps/glfw-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/omakran/MLX42/build/_deps/glfw-subbuild /Users/omakran/MLX42/build/_deps/glfw-subbuild /Users/omakran/MLX42/build/_deps/glfw-subbuild /Users/omakran/MLX42/build/_deps/glfw-subbuild /Users/omakran/MLX42/build/_deps/glfw-subbuild/CMakeFiles/glfw-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/glfw-populate.dir/depend

