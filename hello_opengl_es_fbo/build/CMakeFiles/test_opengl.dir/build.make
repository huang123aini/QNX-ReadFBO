# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/huangshiping/hsp/workspace/hello_opengl_es_fbo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build

# Include any dependencies generated for this target.
include CMakeFiles/test_opengl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_opengl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_opengl.dir/flags.make

CMakeFiles/test_opengl.dir/main.cpp.o: CMakeFiles/test_opengl.dir/flags.make
CMakeFiles/test_opengl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_opengl.dir/main.cpp.o"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_opengl.dir/main.cpp.o -c /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/main.cpp

CMakeFiles/test_opengl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_opengl.dir/main.cpp.i"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/main.cpp > CMakeFiles/test_opengl.dir/main.cpp.i

CMakeFiles/test_opengl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_opengl.dir/main.cpp.s"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/main.cpp -o CMakeFiles/test_opengl.dir/main.cpp.s

CMakeFiles/test_opengl.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/test_opengl.dir/main.cpp.o.requires

CMakeFiles/test_opengl.dir/main.cpp.o.provides: CMakeFiles/test_opengl.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_opengl.dir/build.make CMakeFiles/test_opengl.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/test_opengl.dir/main.cpp.o.provides

CMakeFiles/test_opengl.dir/main.cpp.o.provides.build: CMakeFiles/test_opengl.dir/main.cpp.o


CMakeFiles/test_opengl.dir/FBO.cpp.o: CMakeFiles/test_opengl.dir/flags.make
CMakeFiles/test_opengl.dir/FBO.cpp.o: ../FBO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_opengl.dir/FBO.cpp.o"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_opengl.dir/FBO.cpp.o -c /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/FBO.cpp

CMakeFiles/test_opengl.dir/FBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_opengl.dir/FBO.cpp.i"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/FBO.cpp > CMakeFiles/test_opengl.dir/FBO.cpp.i

CMakeFiles/test_opengl.dir/FBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_opengl.dir/FBO.cpp.s"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/FBO.cpp -o CMakeFiles/test_opengl.dir/FBO.cpp.s

CMakeFiles/test_opengl.dir/FBO.cpp.o.requires:

.PHONY : CMakeFiles/test_opengl.dir/FBO.cpp.o.requires

CMakeFiles/test_opengl.dir/FBO.cpp.o.provides: CMakeFiles/test_opengl.dir/FBO.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_opengl.dir/build.make CMakeFiles/test_opengl.dir/FBO.cpp.o.provides.build
.PHONY : CMakeFiles/test_opengl.dir/FBO.cpp.o.provides

CMakeFiles/test_opengl.dir/FBO.cpp.o.provides.build: CMakeFiles/test_opengl.dir/FBO.cpp.o


CMakeFiles/test_opengl.dir/AFileUtil.cpp.o: CMakeFiles/test_opengl.dir/flags.make
CMakeFiles/test_opengl.dir/AFileUtil.cpp.o: ../AFileUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_opengl.dir/AFileUtil.cpp.o"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_opengl.dir/AFileUtil.cpp.o -c /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/AFileUtil.cpp

CMakeFiles/test_opengl.dir/AFileUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_opengl.dir/AFileUtil.cpp.i"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/AFileUtil.cpp > CMakeFiles/test_opengl.dir/AFileUtil.cpp.i

CMakeFiles/test_opengl.dir/AFileUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_opengl.dir/AFileUtil.cpp.s"
	/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++ --sysroot=/home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/AFileUtil.cpp -o CMakeFiles/test_opengl.dir/AFileUtil.cpp.s

CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.requires:

.PHONY : CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.requires

CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.provides: CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_opengl.dir/build.make CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.provides.build
.PHONY : CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.provides

CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.provides.build: CMakeFiles/test_opengl.dir/AFileUtil.cpp.o


# Object files for target test_opengl
test_opengl_OBJECTS = \
"CMakeFiles/test_opengl.dir/main.cpp.o" \
"CMakeFiles/test_opengl.dir/FBO.cpp.o" \
"CMakeFiles/test_opengl.dir/AFileUtil.cpp.o"

# External object files for target test_opengl
test_opengl_EXTERNAL_OBJECTS =

test_opengl: CMakeFiles/test_opengl.dir/main.cpp.o
test_opengl: CMakeFiles/test_opengl.dir/FBO.cpp.o
test_opengl: CMakeFiles/test_opengl.dir/AFileUtil.cpp.o
test_opengl: CMakeFiles/test_opengl.dir/build.make
test_opengl: CMakeFiles/test_opengl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_opengl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_opengl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_opengl.dir/build: test_opengl

.PHONY : CMakeFiles/test_opengl.dir/build

CMakeFiles/test_opengl.dir/requires: CMakeFiles/test_opengl.dir/main.cpp.o.requires
CMakeFiles/test_opengl.dir/requires: CMakeFiles/test_opengl.dir/FBO.cpp.o.requires
CMakeFiles/test_opengl.dir/requires: CMakeFiles/test_opengl.dir/AFileUtil.cpp.o.requires

.PHONY : CMakeFiles/test_opengl.dir/requires

CMakeFiles/test_opengl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_opengl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_opengl.dir/clean

CMakeFiles/test_opengl.dir/depend:
	cd /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/huangshiping/hsp/workspace/hello_opengl_es_fbo /home/huangshiping/hsp/workspace/hello_opengl_es_fbo /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build /home/huangshiping/hsp/workspace/hello_opengl_es_fbo/build/CMakeFiles/test_opengl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_opengl.dir/depend

