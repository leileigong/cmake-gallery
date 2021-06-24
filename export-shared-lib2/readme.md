## 制作一个共享库并安装库到指定位置

1. 定义一个变量LIB_SHARED_TYPE用于命令控制输出静态共享库或动态共享库
2. 生成的库默认路径在build目录的子目录下，修改保存库的路径为顶层工程根目录下的`lib`目录。
3. 使用接口add_library创建一个名称为`testlib`的库。
4. 添加变量`LIB_SHARED_TYPE`控制输出静态库类型。`LIB_SHARED_TYPE=stc`, 指定编译静生成态库。
5. 安装库文件


### 工程目录结构
```sh
[root@VM-0-9-centos export-shared-lib2]# tree
.
|-- build
|-- CMakeLists.txt
|-- lib
|   |-- Debug
|   |   |-- testlib.dll
|   |   |-- testlib.ilk
|   |   `-- testlib.pdb
|   |-- libtestlib.a
|   |-- libtestlib.so
|   `-- Release
|       |-- testlib.dll
|       `-- testlib.lib
|-- readme.md
`-- util
    |-- array.c
    `-- array.h
```

> **NOTE:**
> 在*nix平台编译后，安装使用make install命令；在windows上使用VS构建后，需要通过devenv程序完成安装。
> devenv export-shared-lib.sln /Build  "Debug|Win32"
> devenv export-shared-lib.sln /Build  "Debug|Win32" /Project "INSTALL"

> **NOTE:**
> 安装位置可以通过`CMAKE_INSTALL_PREFIX`修改。
> 默认安装位置：
> - *nix: ``/usr/local`` 
> - Windows: ``c:/Program Files/${PROJECT_NAME}``
> **默认安装到C:/Program Files(x86)/目录下，但是需要管理员权限**




### Windows平台构建
#### 工程配置
> cmake .. -DCMAKE_INSTALL_PREFIX="D:/Program Files (x86)/testlib"

指定库安装位置：`D:/Program Files (x86)/testlib`
```powershell
PS E:\code\cmake-gallery\export-shared-lib2\build> cmake .. -DCMAKE_INSTALL_PREFIX="D:/Program Files (x86)/testlib"
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
-- Build files have been written to: E:/code/cmake-gallery/export-shared-lib2/build
PS E:\code\cmake-gallery\export-shared-lib2\build>
```

#### 编译

> 使用Release版编译，Debug版编译有问题
> devenv export-shared-lib.sln /Build  "Release|Win32" /Project "INSTALL"

输出：在源码根目录下生成静态库文件`lib\Release\testlib.lib`
安装：
头文件安装位置D:/Program Files (x86)/testlib/include/array.h
库文件安装位置：D:/Program Files (x86)/testlib/lib/testlib.lib

```powershell
PS E:\code\cmake-gallery\export-shared-lib2\build> devenv export-shared-lib.sln /Build  "Release|Win32" /Project "INSTALL"

Microsoft Visual Studio 2015 14.0.23107.0 版。
版权所有 (C) Microsoft Corp。保留所有权利。
1>------ 已启动生成: 项目: ZERO_CHECK, 配置: Release Win32 ------
1>  Checking Build System
2>------ 已启动生成: 项目: testlib, 配置: Release Win32 ------
2>  Building Custom Rule E:/code/cmake-gallery/export-shared-lib2/CMakeLists.txt
2>  array.c
2>  testlib.vcxproj -> E:\code\cmake-gallery\export-shared-lib2\lib\Release\testlib.dll
3>------ 已启动生成: 项目: ALL_BUILD, 配置: Release Win32 ------
3>  Building Custom Rule E:/code/cmake-gallery/export-shared-lib2/CMakeLists.txt
4>------ 已启动生成: 项目: INSTALL, 配置: Release Win32 ------
4>  -- Install configuration: "Release"
4>  -- Installing: D:/Program Files (x86)/testlib/include/array.h
4>  -- Installing: D:/Program Files (x86)/testlib/lib/testlib.lib
========== 生成: 成功 4 个，失败 0 个，最新 0 个，跳过 0 个 ==========
PS E:\code\cmake-gallery\export-shared-lib2\build>
```

### linux(CentOS)平台构建
1)默认配置为生成动态库libtestlib.so
```bash
[root@VM-0-9-centos build]# cmake ..
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /root/cmake-gallery/export-shared-lib2/build
[root@VM-0-9-centos build]# 
```

编译：
```sh
[root@VM-0-9-centos build]# cmake --build .
[ 50%] Building C object CMakeFiles/testlib.dir/util/array.c.o
[100%] Linking C shared library ../lib/libtestlib.so
[100%] Built target testlib
[root@VM-0-9-centos build]# 
```

安装：
```sh
[root@VM-0-9-centos build]# make install
Consolidate compiler generated dependencies of target testlib
[100%] Built target testlib
Install the project...
-- Install configuration: ""
-- Up-to-date: /usr/local/include/array.h
-- Installing: /usr/local/lib/libtestlib.so
```

2)指定生成静态库libtestlib.a
```bash
[root@VM-0-9-centos build]# cmake .. -DLIB_SHARED_TYPE=stc
-- The C compiler identification is GNU 4.8.5
-- The CXX compiler identification is GNU 4.8.5
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /root/cmake-gallery/export-shared-lib2/build
[root@VM-0-9-centos build]# 
```

编译：
```sh
[root@VM-0-9-centos build]# cmake --build .
[ 50%] Building C object CMakeFiles/testlib.dir/util/array.c.o
[100%] Linking C static library ../lib/libtestlib.a
[100%] Built target testlib
[root@VM-0-9-centos build]# 
```

安装：
```sh
[root@VM-0-9-centos build]# make install
Consolidate compiler generated dependencies of target testlib
[100%] Built target testlib
Install the project...
-- Install configuration: ""
-- Up-to-date: /usr/local/include/array.h
-- Installing: /usr/local/lib/libtestlib.a
[root@VM-0-9-centos build]#
```