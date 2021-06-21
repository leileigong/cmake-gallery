cmake_minimum_required(VERSION 3.13.1)

project(import-static-lib)

include_directories(.)

# 必须在add_executable之前调用
link_directories( ${PROJECT_SOURCE_DIR}/lib) #指定动态连接库的路径

add_executable(app main.c)

target_link_libraries(app testlib)




