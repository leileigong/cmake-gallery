## 生成动态库和静态库

1. 定义一个变量LIB_SHARED_TYPE用于命令控制输出静态共享库或动态共享库
2. 生成的库默认路径在build目录的子目录下，修改保存库的路径为顶层工程根目录下的`lib`目录。
3. 使用接口add_library创建一个名称为`testlib`的库。
4. 添加变量`LIB_SHARED_TYPE`控制输出静态库类型。`LIB_SHARED_TYPE=dyn-stc`, 指定编译静生成动态库和静态库。

### 工程目录结构
```sh
$ tree
.
|-- CMakeLists.txt
|-- build
|-- lib
|-- readme.md
`-- util
    |-- array.c
    `-- array.h

4 directories, 6 files
```

### Windows平台构建
#### 工程配置
```sh
$ cmake .. -DLIB_SHARED_TYPE=dyn-stc
-- Building for: Visual Studio 14 2015
-- Selecting Windows SDK version  to target Windows 10.0.19044.
-- The C compiler identification is MSVC 19.0.23506.0
-- The CXX compiler identification is MSVC 19.0.23506.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: D:/work/code/cmake-gallery/export-shared&static-lib/build
```

#### 编译

在源码根目录下生成静态库文件`lib\Debug\testlib.dll和testlib.lib`
```sh
$ cmake --build .
Microsoft (R) 生成引擎版本 14.0.24720.0
版权所有(C) Microsoft Corporation。保留所有权利。

  Checking Build System
  Building Custom Rule D:/work/code/cmake-gallery/export-shared&static-lib/CMakeLists.txt
  array.c
  testlib_shared.vcxproj -> D:\work\code\cmake-gallery\export-shared&static-lib\lib\Debug\testlib.dll
  testlib_shared.vcxproj -> D:/work/code/cmake-gallery/export-shared&static-lib/lib/Debug/testlib.pdb (Full PDB)
  Building Custom Rule D:/work/code/cmake-gallery/export-shared&static-lib/CMakeLists.txt
  array.c
  testlib_static.vcxproj -> D:\work\code\cmake-gallery\export-shared&static-lib\lib\Debug\testlib.lib
  Building Custom Rule D:/work/code/cmake-gallery/export-shared&static-lib/CMakeLists.txt
```

### linux(CentOS)平台构建

