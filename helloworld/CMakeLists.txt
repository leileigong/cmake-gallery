cmake_minimum_required(VERSION 3.13.1)

project(helloworld-project)

add_executable(helloworld main.c)


# 相当于在命令行里运行cmake添加的参数：--config Release
# CMAKE_CONFIGURATION_TYPES可取四个值：Debug;Release;MinSizeRel;RelWithDebInfo
# SET(CMAKE_CONFIGURATION_TYPES "Release")

if(WIN32 AND NOT MINGW)   
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
SET_TARGET_PROPERTIES(helloworld PROPERTIES COMPILE_FLAGS "/Od")
endif(WIN32 AND NOT MINGW)
