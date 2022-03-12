set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

#set(CMAKE_SYSROOT /home/jeason/extra/ws/SDP/qnx710/target/qnx7/aarch64le)
#set(tools /home/jeason/extra/ws/SDP/qnx710/host/linux/x86_64)
#set(CMAKE_C_COMPILER ${tools}/usr/bin/aarch64-unknown-nto-qnx7.1.0-gcc)
#set(CMAKE_CXX_COMPILER ${tools}/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++)

set(CMAKE_SYSROOT /home/huangshiping/hsp/workspace/sdp/SDP/qnx710/target/qnx7/aarch64le)

set(tools /home/huangshiping/hsp/workspace/sdp/SDP/qnx710/host/linux/x86_64)
set(CMAKE_C_COMPILER ${tools}/usr/bin/aarch64-unknown-nto-qnx7.1.0-gcc)
set(CMAKE_CXX_COMPILER ${tools}/usr/bin/aarch64-unknown-nto-qnx7.1.0-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
