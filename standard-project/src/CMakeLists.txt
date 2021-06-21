# 添加依赖库的头文件目录,在源文件中include使用相对路径即可
include_directories(${PROJECT_SOURCE_DIR}/utillib/include)

# 指定可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

aux_source_directory(. DIR_SRC)

add_executable(app ${DIR_SRC})

target_link_libraries(app testlib)
