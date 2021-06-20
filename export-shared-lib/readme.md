## 制作一个共享库

1. 定义一个变量LIB_SHARED_TYPE用于命令控制输出静态共享库或动态共享库
2. 生成的库默认路径在build目录的子目录下，修改保存库的路径为顶层工程根目录下的`lib`目录。
3. 使用接口add_library创建一个名称为`testlib`的库。

### 工程配置
命令：`cmake .. -DLIB_SHARED_TYPE=stc`
LIB_SHARED_TYPE=stc, 指定编译静生成态库。

```powershell
PS E:\code\cmake-gallery\export-shared-lib\build> cmake .. -DLIB_SHARED_TYPE=stc
-- Selecting Windows SDK version  to target Windows 10.0.17134.
-- Configuring done
-- Generating done
-- Build files have been written to: E:/code/cmake-gallery/export-shared-lib/build
PS E:\code\cmake-gallery\export-shared-lib\build>
PS E:\code\cmake-gallery\export-shared-lib\build> cmake .. -DLIB_SHARED_TYPE=stc
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
-- Build files have been written to: E:/code/cmake-gallery/export-shared-lib/build
PS E:\code\cmake-gallery\export-shared-lib\build>
```

### 编译

在源码根目录下生成静态库文件`lib\Release\testlib.lib`
```powershell
PS E:\code\cmake-gallery\export-shared-lib\build> cmake --build . --config Release
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  Checking Build System
  Building Custom Rule E:/code/cmake-gallery/export-shared-lib/CMakeLists.txt
  array.c
  testlib.vcxproj -> E:\code\cmake-gallery\export-shared-lib\lib\Release\testlib.lib
  Building Custom Rule E:/code/cmake-gallery/export-shared-lib/CMakeLists.txt
PS E:\code\cmake-gallery\export-shared-lib\build>
```