## import-static-lib2

> 本示例演示如何通过`find_package`导入自定义库文件

### 工程目录结构
```
[root@VM-0-9-centos import-static-lib2]# tree
.
|-- build
|-- cmake
|   `-- Findtestlib.cmake
|-- CMakeLists.txt
|-- main.c
`-- readme.md

2 directories, 4 files
```

### windows平台构建
> 需要先运行`import-static-lib2`工程，安装testlib库安装在`D:\Program Files (x86)\testlib`下。

step1.在helloworld目录下创建build目录，存放构建目标和临时文件
```powershell
PS> mkdir build
```

step2.在build目录下配置工程

> 需要事先安装一种C编译器，这里使用VS2015。

```powershell
PS E:\code\cmake-gallery\import-static-lib2\build> cmake ..
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
-- Build files have been written to: E:/code/cmake-gallery/import-static-lib2/build
PS E:\code\cmake-gallery\import-static-lib2\build>
```

setp3.编译工程

Relase版的命令：
`cmake --build . --config  Release`

```powershell
PS E:\code\cmake-gallery\import-static-lib2\build> cmake --build . --config  Release
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  Checking Build System
  Building Custom Rule E:/code/cmake-gallery/import-static-lib2/CMakeLists.txt
  main.c
  app.vcxproj -> E:\code\cmake-gallery\import-static-lib2\build\Release\app.exe
  Building Custom Rule E:/code/cmake-gallery/import-static-lib2/CMakeLists.txt
PS E:\code\cmake-gallery\import-static-lib2\build>
```

### linux(CentOS)平台构建
```shell
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
-- Build files have been written to: /root/cmake-gallery/import-static-lib2/build
[root@VM-0-9-centos build]# 
[root@VM-0-9-centos build]# make
[ 50%] Building C object CMakeFiles/app.dir/main.c.o
[100%] Linking C executable app
[100%] Built target app
[root@VM-0-9-centos build]# ./app 
1 2 3 4 5 6 
```

