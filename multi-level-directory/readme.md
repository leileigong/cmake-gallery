### 实现方法一： 在add_executable中手动列出所有的源文件
```makefile
 add_executable(app main.c util/array.c)
```

### 实现方法二：使用aux_source_directory
aux_source_directory自动搜索指定目录下的源文件，并保存在变量中，然后在add_executable在引用。

```makefile
cmake_minimum_required(VERSION 3.13.1)

project(multi-level-directory)

# 实现方法一： 在add_executable中手动列出所有的源文件
# add_executable(app main.c util/array.c)

# 实现方法二：aux_source_directory
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
aux_source_directory(util DIR_SRCS2)
set(SRC_FILES ${DIR_SRCS} ${DIR_SRCS2})
add_executable(app ${SRC_FILES})
```

编译运行：
```sh
PS > cmake --build . --target app --config  Release
CMake is re-running because E:/code/cmake-gallery/multi-level-directory/build/CMakeFiles/generate.stamp is out-of-date.
  the file 'E:/code/cmake-gallery/multi-level-directory/CMakeLists.txt'
  is newer than 'E:/code/cmake-gallery/multi-level-directory/build/CMakeFiles/generate.stamp.depend'
  result='-1'
-- Selecting Windows SDK version  to target Windows 10.0.17134.
-- Configuring done
-- Generating done
-- Build files have been written to: E:/code/cmake-gallery/multi-level-directory/build
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  app.vcxproj -> E:\code\cmake-gallery\multi-level-directory\build\Release\app.exe

PS > E:\code\cmake-gallery\multi-level-directory\build\Release\app.exe
1 2 3 4 5 6
```