# cmake-gallery
cmake一些学习示例

## hello world
[第一个cmake工程hello world](helloworld\readme.md)


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