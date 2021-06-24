cmake_minimum_required(VERSION 3.13.1)

project(export-shared-lib2)

# 添加变量LIB_SHARED_TYPE，命令控制生成库的类型。默认生成动态库
set(LIB_SHARED_TYPE "dyn" CACHE STRING "")

# 生成的库默认路径在build目录下，修改路径
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

aux_source_directory(${PROJECT_SOURCE_DIR}/util SRC_LIST)
set(LIB_SRC ${SRC_LIST})
if(${LIB_SHARED_TYPE} STREQUAL  "stc")  
    add_library(testlib STATIC ${LIB_SRC})
else()
    add_library(testlib SHARED ${LIB_SRC})
endif()

# windows上因为权限问题，需要使用CMAKE_INSTALL_PREFIX选项修改默认的安装位置
install(FILES util/array.h DESTINATION include)
install(TARGETS testlib     # add_library指定的target名称
        ARCHIVE DESTINATION lib) 

