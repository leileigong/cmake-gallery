## stardard-project-en-compile-options-2
### 目录结构
```shell
[root@VM-0-9-centos standard-project-en-compile-options-2]# tree
.
|-- build
|-- CMakeLists.txt
|-- config.h.in
|-- lib
|   |-- CMakeLists.txt.bak
|   |-- include
|   |   `-- array
|   |       `-- array.h
|   |-- libtestlib.a
|   |-- libtestlib.so
|   |-- testlib.dll
|   `-- testlib.lib
|-- readme.md
|-- src
|   `-- main.c
`-- utillib
    |-- array.c
    |-- CMakeLists.txt
    `-- include
        `-- array
            `-- array.h

8 directories, 13 files
```
> 工程根目录下一个CMakeLists文件，库源码目录utillib有一个CMakeLists文件。


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
#### 默认配置

```shell
> cd build
> cmake ..
> cmake --build . --config Release
> .\bin\Release\app.exe
```

#### 更改编译选项USE_BIN_LIB_FILE=OFF
```shell
> cd build 
> cmake .. -DUSE_BIN_LIB_FILE=OFF
> cmake --build . --config Release
> .\bin\Release\app.exe
```

### linux平台构建
#### 默认配置
```sh
[root@VM-0-9-centos build]# cd build
[root@VM-0-9-centos build]# cmake ..
[root@VM-0-9-centos build]# make
[root@VM-0-9-centos build]# bin/app
```

#### 更改编译选项USE_BIN_LIB_FILE=OFF
```sh
[root@VM-0-9-centos standard-project-en-compile-options-2]# rm -rf build/*
[root@VM-0-9-centos build]# cd build
[root@VM-0-9-centos build]# cmake .. -DUSE_BIN_LIB_FILE=OFF
[root@VM-0-9-centos build]# make
[root@VM-0-9-centos build]# bin/app
```