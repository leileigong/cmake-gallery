[toc]

# cmake-gallery
cmake一些学习示例

## hello world
[第一个cmake工程hello world](helloworld/readme.md)

## multi-level-directory
[cmake构建多级源码目录工程](multi-level-directory/readme.md)

## export-shared-lib
[编译生成共享库（动态或静态）](export-shared-lib/readme.md)

## import-static-lib
[引用外部共享库库](import-static-lib/readme.md)

> 使用VS工程时，链接报错,暂时没找到解决办法。
> LINK : fatal error LNK1181: 无法打开输入文件“testlib-NOTFOUND.obj” [E:\code\cmake-gallery\import-static-lib\build\app.vcxproj]

## standard-cmake-project
[标准CMake工程样例](standard-project/readme.md)

## standard-cmake-project-en-compile-options
[标准CMake工程样例-使用编译选项](standard-project-en-compile-options/readme.md)

在顶层CMakeLists.txt中增加两个编译选项:
- `USE_BIN_LIB_FILE` : 控制编译第三方库源码或使用编译好的第三库二进制文件
- `ENABLE_LOG`: 在源文件中使用开启日志输出


## Keil-Arm-demo
Keil-Arm-demo是由cmake构建的最简单的`hello world`工程。目录结构如下：
```sh
$ tree
.
|-- CMakeLists.txt
|-- mdk
|   |-- Listings
|   |   |-- demoproject.map
|   |   `-- startup_armcm0.lst
|   |-- Objects
|   |   |-- demoproject.axf
|   |   |-- demoproject.build_log.htm
|   |   |-- demoproject.hex
|   |   |-- demoproject.htm
|   |   |-- demoproject.lnp
|   |   |-- demoproject.sct
|   |   |-- demoproject_Target 1.dep
|   |   |-- main.crf
|   |   |-- main.d
|   |   |-- main.o
|   |   |-- startup_armcm0.d
|   |   |-- startup_armcm0.o
|   |   |-- system_armcm0.crf
|   |   |-- system_armcm0.d
|   |   `-- system_armcm0.o
|   |-- RTE
|   |   |-- Device
|   |   |   `-- ARMCM0
|   |   |       |-- startup_ARMCM0.s
|   |   |       `-- system_ARMCM0.c
|   |   `-- RTE_Components.h
|   |-- demoproject.uvoptx
|   `-- demoproject.uvprojx
`-- src
    `-- main.c
```


`Keil-Arm-demo/mdk`目录包含一个有keil5创建的Target为Cortex-CM0的最简单的工程。

`Keil-Arm-demo/CMakeLists.txt`配置了ARMCC编译器，并完成对demo工程的编译。