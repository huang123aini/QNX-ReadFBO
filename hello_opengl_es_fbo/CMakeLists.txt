cmake_minimum_required(VERSION 3.5)
project (avm)


#此处的qnx  lib库设置为自己的路径
set(gles_include /home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/usr/include)
INCLUDE_DIRECTORIES(${gles_include})

set(egl_lib libEGL.so)
set(gles_lib libGLESv2.so)
set(screen_lib libscreen.so)

set(gles_lib_dir /home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le/usr/lib)
LINK_DIRECTORIES(${gles_lib_dir})

add_executable(test_opengl ./main.cpp ./FBO.h  ./FBO.cpp  ./AFileUtil.h  ./AFileUtil.cpp)
target_link_libraries(test_opengl ${screen_lib} ${egl_lib} ${gles_lib})
