# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\SOFTWARES\CMake\bin\cmake.exe

# The command to remove a file.
RM = E:\SOFTWARES\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\codebank\DS\expression

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\codebank\DS\expression\build

# Utility rule file for ExperimentalSubmit.

# Include the progress variables for this target.
include CMakeFiles/ExperimentalSubmit.dir/progress.make

CMakeFiles/ExperimentalSubmit:
	E:\SOFTWARES\CMake\bin\ctest.exe -D ExperimentalSubmit

ExperimentalSubmit: CMakeFiles/ExperimentalSubmit
ExperimentalSubmit: CMakeFiles/ExperimentalSubmit.dir/build.make

.PHONY : ExperimentalSubmit

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalSubmit.dir/build: ExperimentalSubmit

.PHONY : CMakeFiles/ExperimentalSubmit.dir/build

CMakeFiles/ExperimentalSubmit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExperimentalSubmit.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalSubmit.dir/clean

CMakeFiles/ExperimentalSubmit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\codebank\DS\expression G:\codebank\DS\expression G:\codebank\DS\expression\build G:\codebank\DS\expression\build G:\codebank\DS\expression\build\CMakeFiles\ExperimentalSubmit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalSubmit.dir/depend
