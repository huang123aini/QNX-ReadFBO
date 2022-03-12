1、Ubuntu 18.4 + QNX SDP 7.1.0
终端 进入 SDP 7.1.0 执行 source  qnxsdp-env.sh 

2、修改CMakeLists.txt里qnx lib库为自己的SDP地址路径  qnx使用gnu++而不是 std++11

3、进入build文件夹 执行  rm -rf *

4、执行 cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmakes/arm-qnx.toolchain.cmake 进行交叉编译

5、build的产出 test_opengl 为qnx可执行文件


Demo功能: 绘制2DTexture到FBO,并读取FBO结果，保存结果。
