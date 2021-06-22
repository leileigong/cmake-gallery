aux_source_directory(. DIR_LIB_SRC)

# PROJECT_BINARY_DIR代表执行camke命令所在的目录
# LIBRARY_OUTPUT_PATH，生成的静态库文件存放路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_library(testlib STATIC ${DIR_LIB_SRC})