## stardard-project-en-compile-options
### 目录结构
```shell
$ tree
.
|-- CMakeLists.txt
|-- build
|-- config.h.in
|-- lib
|   |-- libtestlib.a
|   |-- libtestlib.so
|   |-- testlib.dll
|   `-- testlib.lib
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
```
> 工程根目录下一个CMakeLists文件，且每一级源码目录都有一个CMakeLists文件。


### 开启编译开关步骤
1. 在顶层CMakeLists.txt中使用`option`定义增加的编译选项
   ```makefile
    # 定义编译选项-使能三方二进制库，默认值为`ON`
    option(USE_BIN_LIB_FILE "是否使用编译好的库文件" 
            ON)

    # 定义编译选项-使能日志输出，默认值为`ON`
    option(ENABLE_LOG "是否启用log输出" 
            ON)
   ```
> **注意：**
> 在`src`目录的下`main.c`文件因为包含`#include config.h`文件，需要修改该目录下的CMakeLists.txt文件，包含头文件所在目录。
> ```makefile
> include_directories(${PROJECT_BINARY_DIR}/config)
> ```

2. 创建编译开关配置文件`config.h.in`
3. 在顶层CMakeLists.txt中使用`configure_file`指定编译开关配置文件
   ```makefile
   configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"           # 输入配置文件
    "${PROJECT_BINARY_DIR}/config/config.h"       # 输出配置文件
    )
   ```
4. 在CMakeLists.txt中使用编译开关控制编译逻辑
   ```makefile
   if(USE_BIN_LIB_FILE)
    # 必须在add_executable之前调用
    link_directories(${PROJECT_SOURCE_DIR}/lib) #指定动态连接库的路径
    endif(USE_BIN_LIB_FILE)
   ```
5. 在源文件中使用编译开关控制编译逻辑
   ```c
   #include "config.h"
   ···
    #ifdef ENABLE_LOG  
    printf("\nrun ok!\n");
    #endif
   ```
6. 修改`config.h.in`中编译开关值
   ```sh
   #cmakedefine USE_BIN_LIB_FILE
   #cmakedefine ENABLE_LOG
   ```
7. 配置编译

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
PS E:\code\cmake-gallery\standard-project\build>PS E:\code\cmake-gallery\standard-project-en-compile-options\build> cmake ..
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
-- Build files have been written to: E:/code/cmake-gallery/standard-project-en-compile-options/build
PS E:\code\cmake-gallery\standard-project-en-compile-options\build>
```

#### 编译
```shell
PS E:\code\cmake-gallery\standard-project-en-compile-options\build> cmake --build . --config Release
Microsoft (R) 生成引擎版本 14.0.23107.0
版权所有(C) Microsoft Corporation。保留所有权利。

  Checking Build System
  Building Custom Rule E:/code/cmake-gallery/standard-project-en-compile-options/src/CMakeLists.txt
  main.c
  app.vcxproj -> E:\code\cmake-gallery\standard-project-en-compile-options\build\bin\Release\app.exe
  Building Custom Rule E:/code/cmake-gallery/standard-project-en-compile-options/CMakeLists.txt
PS E:\code\cmake-gallery\standard-project-en-compile-options\build>
```

> 生成的可执行文件路径`build\bin\Release\app.exe`

