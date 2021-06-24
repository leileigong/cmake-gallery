cmake_minimum_required(VERSION 3.13.1)

project(import-static-lib2)

# 指定Findxxx.cmake查找路径
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(testlib REQUIRED)

if(testlib_FOUND)
    add_executable(app main.c)
    target_include_directories(app PRIVATE ${testlib_INCLUDE_DIR})
    target_link_libraries(app ${testlib_LIBRARY})
else(testlib_FOUND)
    message(FATAL_ERROR "testlib not found")
endif(testlib_FOUND)





