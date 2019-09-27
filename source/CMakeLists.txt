# CMake 版本要求
cmake_minimum_required (VERSION 2.8)

# 项目信息 这个就是上一层目录的文件夹名？
project (source)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ggdb")
# error: a space is required between consecutive right angle brackets (use '> >')

####################
# 同一目录，多个源文件。
####################
# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量 
aux_source_directory(. DIR_SRCS)

# 指定生成目标
# add_executable(He helloworld.cpp) # 将 helloworld.cpp 源文件编译成一个名称为 He 的可执行文件。
add_executable(test ${DIR_SRCS}) # 多个源文件编译成一个名称为 He 的可执行文件。

# cmake . 命令会生成 Makefile、CMakeCache.txt、cmake_install.cmake, CMakeFiles整个文件夹
# 然后 make 命令编译，生成可执行文件。
#
# cmake .
# make
