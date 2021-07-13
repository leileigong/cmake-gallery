cmake_minimum_required(VERSION 3.13.1)

project(standard-project-en-compile-options-2)

# 定义编译选项,默认值为`ON`
option(USE_BIN_LIB_FILE "是否使用编译好的库文件" 
        OFF)
option(ENABLE_LOG "是否启用log输出" 
        ON)

# 加入一个配置头文件 config.h ，由CMake根据config.h.in生成
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"           # 输入配置文件
  "${PROJECT_BINARY_DIR}/config/config.h"       # 输出配置文件
  )

# 指定可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(${PROJECT_BINARY_DIR}/config)

if(USE_BIN_LIB_FILE)
    # 必须在add_executable之前调用
    link_directories(${PROJECT_SOURCE_DIR}/lib) #指定动态连接库的路径
    # 添加依赖库的头文件目录,在源文件中include使用相对路径即可
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/lib/include)
else()
    add_subdirectory(utillib)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/utillib/include")
endif(USE_BIN_LIB_FILE)

add_executable(app)
# add_executable如果不指定源文件，需要通过target_sources指定
aux_source_directory(src DIR_SRC)
target_sources(app PUBLIC ${DIR_SRC})

target_link_libraries(app testlib)
target_include_directories(app PUBLIC ${EXTRA_INCLUDES})


