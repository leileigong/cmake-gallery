cmake_minimum_required(VERSION 3.13.1)

project(export-shared_static-lib)

# 添加变量LIB_SHARED_TYPE，命令控制生成库的类型。默认生成动态库
set(LIB_SHARED_TYPE "dyn-stc" CACHE STRING "")

# 生成的库默认路径在build目录下，修改路径
SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

aux_source_directory(${PROJECT_SOURCE_DIR}/util SRC_LIST)
set(LIB_SRC ${SRC_LIST})
if(${LIB_SHARED_TYPE} STREQUAL  "stc")  
    add_library(testlib STATIC ${LIB_SRC})
elseif(${LIB_SHARED_TYPE} STREQUAL  "dyn")
    add_library(testlib SHARED ${LIB_SRC})
else(${LIB_SHARED_TYPE} STREQUAL  "dyn-stc")

    add_library(testlib_shared SHARED ${LIB_SRC})
    # 重命名库名称
    set_target_properties(testlib_shared PROPERTIES OUTPUT_NAME "testlib")
    set_target_properties(testlib_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)

    add_library(testlib_static STATIC ${LIB_SRC})
    set_target_properties(testlib_static PROPERTIES OUTPUT_NAME "testlib")
    set_target_properties(testlib_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

endif()

# 安装共享库
# install(TARGETS testlib_shared testlib_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

