# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gabriel/Experimental/iris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gabriel/Experimental/iris

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gabriel/Experimental/iris/CMakeFiles /home/gabriel/Experimental/iris/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/gabriel/Experimental/iris/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named iris

# Build rule for target.
iris: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 iris
.PHONY : iris

# fast build rule for target.
iris/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/build
.PHONY : iris/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/main.cpp.s
.PHONY : main.cpp.s

src/layer.o: src/layer.cpp.o

.PHONY : src/layer.o

# target to build an object file
src/layer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/layer.cpp.o
.PHONY : src/layer.cpp.o

src/layer.i: src/layer.cpp.i

.PHONY : src/layer.i

# target to preprocess a source file
src/layer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/layer.cpp.i
.PHONY : src/layer.cpp.i

src/layer.s: src/layer.cpp.s

.PHONY : src/layer.s

# target to generate assembly for a file
src/layer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/layer.cpp.s
.PHONY : src/layer.cpp.s

src/matrix.o: src/matrix.cpp.o

.PHONY : src/matrix.o

# target to build an object file
src/matrix.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/matrix.cpp.o
.PHONY : src/matrix.cpp.o

src/matrix.i: src/matrix.cpp.i

.PHONY : src/matrix.i

# target to preprocess a source file
src/matrix.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/matrix.cpp.i
.PHONY : src/matrix.cpp.i

src/matrix.s: src/matrix.cpp.s

.PHONY : src/matrix.s

# target to generate assembly for a file
src/matrix.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/matrix.cpp.s
.PHONY : src/matrix.cpp.s

src/network.o: src/network.cpp.o

.PHONY : src/network.o

# target to build an object file
src/network.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/network.cpp.o
.PHONY : src/network.cpp.o

src/network.i: src/network.cpp.i

.PHONY : src/network.i

# target to preprocess a source file
src/network.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/network.cpp.i
.PHONY : src/network.cpp.i

src/network.s: src/network.cpp.s

.PHONY : src/network.s

# target to generate assembly for a file
src/network.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/network.cpp.s
.PHONY : src/network.cpp.s

src/neuron.o: src/neuron.cpp.o

.PHONY : src/neuron.o

# target to build an object file
src/neuron.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/neuron.cpp.o
.PHONY : src/neuron.cpp.o

src/neuron.i: src/neuron.cpp.i

.PHONY : src/neuron.i

# target to preprocess a source file
src/neuron.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/neuron.cpp.i
.PHONY : src/neuron.cpp.i

src/neuron.s: src/neuron.cpp.s

.PHONY : src/neuron.s

# target to generate assembly for a file
src/neuron.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/neuron.cpp.s
.PHONY : src/neuron.cpp.s

src/utils.o: src/utils.cpp.o

.PHONY : src/utils.o

# target to build an object file
src/utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/utils.cpp.o
.PHONY : src/utils.cpp.o

src/utils.i: src/utils.cpp.i

.PHONY : src/utils.i

# target to preprocess a source file
src/utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/utils.cpp.i
.PHONY : src/utils.cpp.i

src/utils.s: src/utils.cpp.s

.PHONY : src/utils.s

# target to generate assembly for a file
src/utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/iris.dir/build.make CMakeFiles/iris.dir/src/utils.cpp.s
.PHONY : src/utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... iris"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/layer.o"
	@echo "... src/layer.i"
	@echo "... src/layer.s"
	@echo "... src/matrix.o"
	@echo "... src/matrix.i"
	@echo "... src/matrix.s"
	@echo "... src/network.o"
	@echo "... src/network.i"
	@echo "... src/network.s"
	@echo "... src/neuron.o"
	@echo "... src/neuron.i"
	@echo "... src/neuron.s"
	@echo "... src/utils.o"
	@echo "... src/utils.i"
	@echo "... src/utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

