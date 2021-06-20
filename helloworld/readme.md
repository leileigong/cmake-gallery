[toc]

## hello world
工程目录结构
```
$ ls
 CMakeLists.txt  main.cpp  readme.md
```

CMakeLists.txt内容如下：
定义一个target名称为`hello world`:
```makefile
project(helloworld-project)

add_executable(helloworld main.cpp)
```

### 在windows平台上构建
step1.在helloworld目录下创建build目录，存放构建目标和临时文件
```powershell
PS> mkdir build

```

step2.在build目录下配置工程

> 需要事先安装一种C编译器，这里使用VS2015。

```powershell
PS> cd build
PS> cmake ..
-- Building for: Visual Studio 14 2015
-- Selecting Windows SDK version  to target Windows 10.0.17134.
-- The C compiler identification is MSVC 19.0.23026.0
-- The CXX compiler identification is MSVC 19.0.23026.0
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe - works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - failed
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe - works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - failed
-- Detecting CXX compile features
-- Detecting CXX compile features - failed
-- Configuring done
-- Generating done
-- Build files have been written to: E:/code/cmake-gallery/helloworld/build
```

目录结构：
```sh
$ tree
.
|-- ALL_BUILD.vcxproj
|-- ALL_BUILD.vcxproj.filters
|-- CMakeCache.txt
|-- CMakeFiles
|   |-- 3.17.3
|   |   |-- CMakeCCompiler.cmake
|   |   |-- CMakeCXXCompiler.cmake
|   |   |-- CMakeDetermineCompilerABI_C.bin
|   |   |-- CMakeDetermineCompilerABI_CXX.bin
|   |   |-- CMakeRCCompiler.cmake
|   |   |-- CMakeSystem.cmake
|   |   |-- CompilerIdC
|   |   |   |-- CMakeCCompilerId.c
|   |   |   |-- CompilerIdC.exe
|   |   |   |-- CompilerIdC.vcxproj
|   |   |   |-- Debug
|   |   |   |   |-- CMakeCCompilerId.obj
|   |   |   |   `-- CompilerIdC.tlog
|   |   |   |       |-- CL.command.1.tlog
|   |   |   |       |-- CL.read.1.tlog
|   |   |   |       |-- CL.write.1.tlog
|   |   |   |       |-- CompilerIdC.lastbuildstate
|   |   |   |       |-- link.command.1.tlog
|   |   |   |       |-- link.read.1.tlog
|   |   |   |       `-- link.write.1.tlog
|   |   |   `-- tmp
|   |   |-- CompilerIdCXX
|   |   |   |-- CMakeCXXCompilerId.cpp
|   |   |   |-- CompilerIdCXX.exe
|   |   |   |-- CompilerIdCXX.vcxproj
|   |   |   |-- Debug
|   |   |   |   |-- CMakeCXXCompilerId.obj
|   |   |   |   `-- CompilerIdCXX.tlog
|   |   |   |       |-- CL.command.1.tlog
|   |   |   |       |-- CL.read.1.tlog
|   |   |   |       |-- CL.write.1.tlog
|   |   |   |       |-- CompilerIdCXX.lastbuildstate
|   |   |   |       |-- link.command.1.tlog
|   |   |   |       |-- link.read.1.tlog
|   |   |   |       `-- link.write.1.tlog
|   |   |   `-- tmp
|   |   |-- Debug
|   |   |   `-- VCTargetsPath.tlog
|   |   |       `-- VCTargetsPath.lastbuildstate
|   |   |-- VCTargetsPath.txt
|   |   `-- VCTargetsPath.vcxproj
|   |-- CMakeOutput.log
|   |-- CMakeTmp
|   |-- TargetDirectories.txt
|   |-- a9957863dbb03686561b72c6abccaa42
|   |   `-- generate.stamp.rule
|   |-- cmake.check_cache
|   |-- feature_tests.bin
|   |-- feature_tests.cxx
|   |-- generate.stamp
|   |-- generate.stamp.depend
|   `-- generate.stamp.list
|-- ZERO_CHECK.vcxproj
|-- ZERO_CHECK.vcxproj.filters
|-- cmake_install.cmake
|-- helloworld-project.sln
|-- helloworld.vcxproj
`-- helloworld.vcxproj.filters

14 directories, 49 files
```

> 从以上目录中可以看到，解决方案名称`helloworld-project.sln`对应，CMakeLists文件中的project接口传入参数名称。

setp3.编译工程,helloworld为CMakeLists中定义的。
1）编译debug版的命令：
`cmake --build . --target helloworld`
```powershell
PS build> cmake --build . --target helloworld
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  helloworld.vcxproj -> E:\code\cmake-gallery\helloworld\build\Debug\helloworld.exe
PS E:\code\cmake-gallery\helloworld\build>
```

2）编译Relase版的命令：
`cmake --build . --target helloworld --config  Release`

```powershell
PS > cmake --build . --target helloworld --config  Release
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  helloworld.vcxproj -> E:\code\cmake-gallery\helloworld\build\Release\helloworld.exe
```

### 在linux平台上构建

#### 安装依赖
- 编译器gcc或g++(使用GNU 4.8.5)
- cmake (使用3.17.5)

#### 配置编译
```sh
[root@VM-0-9-centos build]# cmake3 ..
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc - works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ - works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /root/cmake-gallery/helloworld/build
[root@VM-0-9-centos build]#
```

#### 编译
```sh
[root@VM-0-9-centos build]# cmake3 --build .
Scanning dependencies of target helloworld
[ 50%] Building C object CMakeFiles/helloworld.dir/main.c.o
[100%] Linking C executable helloworld
[100%] Built target helloworld
[root@VM-0-9-centos build]# ls
CMakeCache.txt  CMakeFiles  cmake_install.cmake  helloworld  Makefile

```

#### 运行
```sh
[root@VM-0-9-centos build]# ./helloworld
hello world
[root@VM-0-9-centos build]#
```
