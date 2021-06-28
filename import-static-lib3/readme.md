## import-static-lib23

> 本示例演示如何通过`find_package`导外标准部第三方库文件（OpenSSL）

### 工程目录结构
```
[root@VM-0-9-centos import-static-lib3]# tree
.
|-- build
|-- CMakeLists.txt
|-- main.c
`-- readme.md

1 directories, 4 files
```

### windows平台构建


> 我这里要编译32位可执行文件，需要下载32位安装包。[从gitee下载OpenSSL-1.1.0](https://gitee.com/mohistH/openssl_exe.git)
> 安装路径：`D:\Program Files (x86)\OpenSSL-Win32`
```
$ tree
.
|-- MinGW
|   |-- libcrypto.def
|   |-- libcrypto.dll.a
|   |-- libssl.def
|   `-- libssl.dll.a
|-- VC
|   |-- libcrypto32MD.lib
|   |-- libcrypto32MDd.lib
|   |-- libcrypto32MT.lib
|   |-- libcrypto32MTd.lib
|   |-- libssl32MD.lib
|   |-- libssl32MDd.lib
|   |-- libssl32MT.lib
|   |-- libssl32MTd.lib
|   `-- static
|       |-- libcrypto32MD.lib
|       |-- libcrypto32MDd.lib
|       |-- libcrypto32MT.lib
|       |-- libcrypto32MTd.lib
|       |-- libssl32MD.lib
|       |-- libssl32MDd.lib
|       |-- libssl32MT.lib
|       `-- libssl32MTd.lib
|-- capi.lib
|-- dasync.lib
|-- libapps.lib
|-- libcrypto.def
|-- libcrypto.lib
|-- libcrypto_static.lib
|-- libssl.def
|-- libssl.lib
|-- libssl_static.lib
|-- libtestutil.lib
|-- openssl.lib
|-- ossltest.lib
|-- padlock.lib
`-- uitest.lib
```


**Tips:**
1. 默认情况下，会链接动态库。
1）生成器为VS2015：
库搜索路径为**D:/Program Files(x86)/OpenSSL-Win32/lib/VC/**
2）生成器为Ninja，用gcc编译:
库搜索路径为**D:/Program Files (x86)/OpenSSL-Win32/lib/MinGW**

2. 如果设置了OPENSSL_USE_STATIC_LIBS会链接静态库
即，`set(OPENSSL_USE_STATIC_LIBS TRUE)`
搜索库路径为**D:/Program Files(x86)/OpenSSL-Win32/lib/VC/static**

> **注意：**
因为静态库对`libcrypto-1_1.dll`有依赖，链接完成后，需要把dll文件拷贝到可执行文件所在目录。

step1.编译选项`OPENSSL_ROOT_DIR`指定OpenSSL跟目录：
```powershell
PS E:\code\cmake-gallery\import-static-lib3\build> cmake .. -DOPENSSL_ROOT_DIR="D:/Program Files (x86)/OpenSSL-Win32"
-- Selecting Windows SDK version  to target Windows 10.0.17134.
CMAKE_CL_64            =0, ADDRESS_MODEL =
OPENSSL_ROOT_DIR       =D:/Program Files (x86)/OpenSSL-Win32
OPENSSL_INCLUDE_DIR    =D:/Program Files (x86)/OpenSSL-Win32/include
OPENSSL_CRYPTO_LIBRARY =optimized;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libcrypto32MD.lib;debug;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libcrypto32MDd.lib
OPENSSL_SSL_LIBRARY    =optimized;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libssl32MD.lib;debug;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libssl32MDd.lib
OpenSSL_LIBRARIES      =optimized;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libssl32MD.lib;debug;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libssl32MDd.lib;optimized;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libcrypto32MD.lib;debug;D:/Program Files (x86)/OpenSSL-Win32/lib/VC/libcrypto32MDd.lib
-- Configuring done
-- Generating done
-- Build files have been written to: E:/code/cmake-gallery/import-static-lib3/build
PS E:\code\cmake-gallery\import-static-lib3\build>
```

step2.编译链接`cmake  --build . --config Release -v`
```powershell
PS E:\code\cmake-gallery\import-static-lib3\build> cmake  --build . --config Release -v
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

生成启动时间为 2021/6/28 19:57:31。
节点 1 上的项目“E:\code\cmake-gallery\import-static-lib3\build\ALL_BUILD.vcxproj”(默认目标)。
项目“E:\code\cmake-gallery\import-static-lib3\build\ALL_BUILD.vcxproj”(1)正在节点 1 上生成“E:\code\cmake-gallery\import-static-l
ib3\build\ZERO_CHECK.vcxproj”(2) (默认目标)。
PrepareForBuild:
  正在创建目录“Win32\Release\ZERO_CHECK\”。
  正在创建目录“E:\code\cmake-gallery\import-static-lib3\build\Release\”。
  正在创建目录“Win32\Release\ZERO_CHECK\ZERO_CHECK.tlog\”。
InitializeBuildStatus:
  正在创建“Win32\Release\ZERO_CHECK\ZERO_CHECK.tlog\unsuccessfulbuild”，因为已指定“AlwaysCreate”。
CustomBuild:
  Checking Build System
FinalizeBuildStatus:
  正在删除文件“Win32\Release\ZERO_CHECK\ZERO_CHECK.tlog\unsuccessfulbuild”。
  正在对“Win32\Release\ZERO_CHECK\ZERO_CHECK.tlog\ZERO_CHECK.lastbuildstate”执行 Touch 任务。
已完成生成项目“E:\code\cmake-gallery\import-static-lib3\build\ZERO_CHECK.vcxproj”(默认目标)的操作。

项目“E:\code\cmake-gallery\import-static-lib3\build\ALL_BUILD.vcxproj”(1)正在节点 1 上生成“E:\code\cmake-gallery\import-static-l
ib3\build\app.vcxproj”(3) (默认目标)。
PrepareForBuild:
  正在创建目录“app.dir\Release\”。
  正在创建目录“app.dir\Release\app.tlog\”。
InitializeBuildStatus:
  正在创建“app.dir\Release\app.tlog\unsuccessfulbuild”，因为已指定“AlwaysCreate”。
CustomBuild:
  Building Custom Rule E:/code/cmake-gallery/import-static-lib3/CMakeLists.txt
ClCompile:
  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\CL.exe /c /I"D:\Program Files (x86)\OpenSSL-Win32\include"
   /nologo /W3 /WX- /O2 /Ob2 /Oy- /D WIN32 /D _WINDOWS /D NDEBUG /D "CMAKE_INTDIR=\"Release\"" /D _MBCS /Gm- /MD /GS /f
  p:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Fo"app.dir\Release\\" /Fd"app.dir\Release\vc140.pdb" /Gd /TC /analyze-
   /errorReport:queue "E:\code\cmake-gallery\import-static-lib3\main.c"
  main.c
Link:
  C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\link.exe /ERRORREPORT:QUEUE /OUT:"E:\code\cmake-gallery\im
  port-static-lib3\build\Release\app.exe" /INCREMENTAL:NO /NOLOGO "D:\Program Files (x86)\OpenSSL-Win32\lib\VC\libcrypt
  o32MD.lib" "D:\Program Files (x86)\OpenSSL-Win32\lib\VC\libssl32MD.lib" "D:\Program Files (x86)\OpenSSL-Win32\lib\VC\
  libcrypto32MD.lib" kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg3
  2.lib advapi32.lib /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /PDB:"E:/code/cmake-ga
  llery/import-static-lib3/build/Release/app.pdb" /SUBSYSTEM:CONSOLE /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"E:/code/c
  make-gallery/import-static-lib3/build/Release/app.lib" /MACHINE:X86 /SAFESEH  /machine:X86 app.dir\Release\main.obj
  app.vcxproj -> E:\code\cmake-gallery\import-static-lib3\build\Release\app.exe
PostBuildEvent:
  setlocal
  "C:\Program Files\CMake\bin\cmake.exe" -E copy "D:/Program Files (x86)/OpenSSL-Win32/libcrypto-1_1.dll" E:/code/cmake
  -gallery/import-static-lib3/build/Release
  if %errorlevel% neq 0 goto :cmEnd
  :cmEnd
  endlocal & call :cmErrorLevel %errorlevel% & goto :cmDone
  :cmErrorLevel
  exit /b %1
  :cmDone
  if %errorlevel% neq 0 goto :VCEnd
  :VCEnd
FinalizeBuildStatus:
  正在删除文件“app.dir\Release\app.tlog\unsuccessfulbuild”。
  正在对“app.dir\Release\app.tlog\app.lastbuildstate”执行 Touch 任务。
已完成生成项目“E:\code\cmake-gallery\import-static-lib3\build\app.vcxproj”(默认目标)的操作。

PrepareForBuild:
  正在创建目录“Win32\Release\ALL_BUILD\”。
  正在创建目录“Win32\Release\ALL_BUILD\ALL_BUILD.tlog\”。
InitializeBuildStatus:
  正在创建“Win32\Release\ALL_BUILD\ALL_BUILD.tlog\unsuccessfulbuild”，因为已指定“AlwaysCreate”。
CustomBuild:
  Building Custom Rule E:/code/cmake-gallery/import-static-lib3/CMakeLists.txt
FinalizeBuildStatus:
  正在删除文件“Win32\Release\ALL_BUILD\ALL_BUILD.tlog\unsuccessfulbuild”。
  正在对“Win32\Release\ALL_BUILD\ALL_BUILD.tlog\ALL_BUILD.lastbuildstate”执行 Touch 任务。
已完成生成项目“E:\code\cmake-gallery\import-static-lib3\build\ALL_BUILD.vcxproj”(默认目标)的操作。


已成功生成。
    0 个警告
    0 个错误

已用时间 00:00:03.40
```

step3.运行测试
```powershell
PS E:\code\cmake-gallery\import-static-lib3\build> E:\code\cmake-gallery\import-static-lib3\build\Release\app.exe
hash input data:00010203040506070809
SHA1 output:DA39A3EE5E6B4B0D3255BFEF95601890AFD80709
PS E:\code\cmake-gallery\import-static-lib3\build>
```


### linux(CentOS)平台构建
```sh
  yum install openssl
  yum install openssl-devel
```

> 说明：在linux平台不需要显示使用编译选项`OPENSSL_ROOT_DIR`指定OpenSSL跟目录


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
-- Found OpenSSL: /usr/lib64/libcrypto.so (found version "1.0.2k")  
CMAKE_CL_64            =, ADDRESS_MODEL = 
OPENSSL_ROOT_DIR       =
OPENSSL_INCLUDE_DIR    =/usr/include
OPENSSL_CRYPTO_LIBRARY =/usr/lib64/libcrypto.so
OPENSSL_SSL_LIBRARY    =/usr/lib64/libssl.so
OpenSSL_LIBRARIES      =/usr/lib64/libssl.so;/usr/lib64/libcrypto.so
-- Configuring done
-- Generating done
-- Build files have been written to: /root/cmake-gallery/import-static-lib3/build
[root@VM-0-9-centos build]# 
[root@VM-0-9-centos build]# make
[ 50%] Building C object CMakeFiles/app.dir/main.c.o
[100%] Linking C executable app
[100%] Built target app
[root@VM-0-9-centos build]# ./app 
hash input data:00010203040506070809
SHA1 output:DA39A3EE5E6B4B0D3255BFEF95601890AFD80709
[root@VM-0-9-centos build]# 
```

