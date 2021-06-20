cmake_minimum_required(VERSION 3.13.1)

project(multi-level-directory)

# 实现方法一： 在add_executable中手动列出所有的源文件
# add_executable(app main.c util/array.c)

# 实现方法二：aux_source_directory
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
aux_source_directory(util DIR_SRCS2)
set(SRC_FILES ${DIR_SRCS} ${DIR_SRCS2})
add_executable(app ${SRC_FILES})

