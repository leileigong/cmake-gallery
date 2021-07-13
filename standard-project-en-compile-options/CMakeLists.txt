cmake_minimum_required(VERSION 3.13.1)

project(standard-project-en-compile-options)

# 加入一个配置头文件 config.h ，由CMake根据config.h.in生成
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"           # 输入配置文件
  "${PROJECT_BINARY_DIR}/config/config.h"       # 输出配置文件
  )

# 定义编译选项-使能三方二进制库，默认值为`ON`
option(USE_BIN_LIB_FILE "是否使用编译好的库文件" 
        ON)

# 定义编译选项-使能日志输出，默认值为`ON`
option(ENABLE_LOG "是否启用log输出" 
        ON)


if(USE_BIN_LIB_FILE)
    # 必须在add_executable之前调用
    link_directories(${PROJECT_SOURCE_DIR}/lib) #指定动态连接库的路径
else()
    add_subdirectory(utillib)
endif(USE_BIN_LIB_FILE)

add_subdirectory(src)

