# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TP_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP_1.dir/flags.make

CMakeFiles/TP_1.dir/main.c.obj: CMakeFiles/TP_1.dir/flags.make
CMakeFiles/TP_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TP_1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP_1.dir\main.c.obj   -c "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\main.c"

CMakeFiles/TP_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP_1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\main.c" > CMakeFiles\TP_1.dir\main.c.i

CMakeFiles/TP_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP_1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\main.c" -o CMakeFiles\TP_1.dir\main.c.s

CMakeFiles/TP_1.dir/main.c.obj.requires:

.PHONY : CMakeFiles/TP_1.dir/main.c.obj.requires

CMakeFiles/TP_1.dir/main.c.obj.provides: CMakeFiles/TP_1.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\TP_1.dir\build.make CMakeFiles/TP_1.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/TP_1.dir/main.c.obj.provides

CMakeFiles/TP_1.dir/main.c.obj.provides.build: CMakeFiles/TP_1.dir/main.c.obj


CMakeFiles/TP_1.dir/patricia.c.obj: CMakeFiles/TP_1.dir/flags.make
CMakeFiles/TP_1.dir/patricia.c.obj: ../patricia.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TP_1.dir/patricia.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP_1.dir\patricia.c.obj   -c "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\patricia.c"

CMakeFiles/TP_1.dir/patricia.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP_1.dir/patricia.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\patricia.c" > CMakeFiles\TP_1.dir\patricia.c.i

CMakeFiles/TP_1.dir/patricia.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP_1.dir/patricia.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\patricia.c" -o CMakeFiles\TP_1.dir\patricia.c.s

CMakeFiles/TP_1.dir/patricia.c.obj.requires:

.PHONY : CMakeFiles/TP_1.dir/patricia.c.obj.requires

CMakeFiles/TP_1.dir/patricia.c.obj.provides: CMakeFiles/TP_1.dir/patricia.c.obj.requires
	$(MAKE) -f CMakeFiles\TP_1.dir\build.make CMakeFiles/TP_1.dir/patricia.c.obj.provides.build
.PHONY : CMakeFiles/TP_1.dir/patricia.c.obj.provides

CMakeFiles/TP_1.dir/patricia.c.obj.provides.build: CMakeFiles/TP_1.dir/patricia.c.obj


CMakeFiles/TP_1.dir/auxprocedures.c.obj: CMakeFiles/TP_1.dir/flags.make
CMakeFiles/TP_1.dir/auxprocedures.c.obj: ../auxprocedures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TP_1.dir/auxprocedures.c.obj"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\TP_1.dir\auxprocedures.c.obj   -c "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\auxprocedures.c"

CMakeFiles/TP_1.dir/auxprocedures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TP_1.dir/auxprocedures.c.i"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\auxprocedures.c" > CMakeFiles\TP_1.dir\auxprocedures.c.i

CMakeFiles/TP_1.dir/auxprocedures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TP_1.dir/auxprocedures.c.s"
	C:\MinGW\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\auxprocedures.c" -o CMakeFiles\TP_1.dir\auxprocedures.c.s

CMakeFiles/TP_1.dir/auxprocedures.c.obj.requires:

.PHONY : CMakeFiles/TP_1.dir/auxprocedures.c.obj.requires

CMakeFiles/TP_1.dir/auxprocedures.c.obj.provides: CMakeFiles/TP_1.dir/auxprocedures.c.obj.requires
	$(MAKE) -f CMakeFiles\TP_1.dir\build.make CMakeFiles/TP_1.dir/auxprocedures.c.obj.provides.build
.PHONY : CMakeFiles/TP_1.dir/auxprocedures.c.obj.provides

CMakeFiles/TP_1.dir/auxprocedures.c.obj.provides.build: CMakeFiles/TP_1.dir/auxprocedures.c.obj


# Object files for target TP_1
TP_1_OBJECTS = \
"CMakeFiles/TP_1.dir/main.c.obj" \
"CMakeFiles/TP_1.dir/patricia.c.obj" \
"CMakeFiles/TP_1.dir/auxprocedures.c.obj"

# External object files for target TP_1
TP_1_EXTERNAL_OBJECTS =

TP_1.exe: CMakeFiles/TP_1.dir/main.c.obj
TP_1.exe: CMakeFiles/TP_1.dir/patricia.c.obj
TP_1.exe: CMakeFiles/TP_1.dir/auxprocedures.c.obj
TP_1.exe: CMakeFiles/TP_1.dir/build.make
TP_1.exe: CMakeFiles/TP_1.dir/linklibs.rsp
TP_1.exe: CMakeFiles/TP_1.dir/objects1.rsp
TP_1.exe: CMakeFiles/TP_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable TP_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TP_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP_1.dir/build: TP_1.exe

.PHONY : CMakeFiles/TP_1.dir/build

CMakeFiles/TP_1.dir/requires: CMakeFiles/TP_1.dir/main.c.obj.requires
CMakeFiles/TP_1.dir/requires: CMakeFiles/TP_1.dir/patricia.c.obj.requires
CMakeFiles/TP_1.dir/requires: CMakeFiles/TP_1.dir/auxprocedures.c.obj.requires

.PHONY : CMakeFiles/TP_1.dir/requires

CMakeFiles/TP_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TP_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TP_1.dir/clean

CMakeFiles/TP_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras" "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras" "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug" "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug" "D:\Cloud_Storage\OneDrive\Faculdade\Semestre 3\AEDS II\Exercicios\Primeiro_TP\Patricia_Letras\cmake-build-debug\CMakeFiles\TP_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TP_1.dir/depend
