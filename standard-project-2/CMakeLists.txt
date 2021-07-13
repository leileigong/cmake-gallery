cmake_minimum_required(VERSION 3.13.1)

project(standard-project-2)

add_subdirectory(utillib)   # 编译输出testlib.lib/libtestlib.so

aux_source_directory(src DIR_SRC)
add_executable(app ${DIR_SRC})
# 指定可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

target_link_libraries(app PUBLIC testlib)

# 添加依赖库的头文件目录,在源文件中include使用相对路径即可
# include_directories(${PROJECT_SOURCE_DIR}/utillib/include)
target_include_directories(app PUBLIC 
                                "${PROJECT_BINARY_DIR}"
                                ${PROJECT_SOURCE_DIR}/utillib/include
                            )



