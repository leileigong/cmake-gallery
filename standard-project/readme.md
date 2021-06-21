## stardard-project
### 目录结构
```shell
$ tree
.
|-- CMakeLists.txt
|-- build
|-- readme.md
|-- src
|   |-- CMakeLists.txt
|   `-- main.c
`-- utillib
    |-- CMakeLists.txt
    |-- array.c
    `-- include
        `-- array
            `-- array.h

5 directories, 7 files
```

> 工程根目录下一个CMakeLists文件，且每一级源码目录都有一个CMakeLists文件。

### Windows平台构建
#### 配置工程

```shell
PS E:\code\cmake-gallery\standard-project\build> cmake ..
-- Building for: Visual Studio 14 2015
-- Selecting Windows SDK version  to target Windows 10.0.17134.
-- The C compiler identification is MSVC 19.0.23026.0
-- The CXX compiler identification is MSVC 19.0.23026.0
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe - works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe - works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: E:/code/cmake-gallery/standard-project/build
PS E:\code\cmake-gallery\standard-project\build>
```

#### 编译
```shell
PS E:\code\cmake-gallery\standard-project\build> cmake --build . --config Release
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  Checking Build System
  Building Custom Rule E:/code/cmake-gallery/standard-project/utillib/CMakeLists.txt
  array.c
  testlib.vcxproj -> E:\code\cmake-gallery\standard-project\build\lib\Release\testlib.lib
  Building Custom Rule E:/code/cmake-gallery/standard-project/src/CMakeLists.txt
  main.c
  app.vcxproj -> E:\code\cmake-gallery\standard-project\build\bin\Release\app.exe
  Building Custom Rule E:/code/cmake-gallery/standard-project/CMakeLists.txt
PS E:\code\cmake-gallery\standard-project\build>
```

> 生成的静态库路径在`build\lib\Release\testlib.lib`下，生成的可执行文件路径`build\bin\Release\app.exe`

