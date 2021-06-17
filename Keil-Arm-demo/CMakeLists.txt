cmake_minimum_required(VERSION 3.13.1)

# 大多数的工程还是用的armcc编译，配置cmake用的armcc编译链来进行编译
# 也可以使用armclang或者armgcc编译，但是比较麻烦
set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_SYSTEM_VERSION 1.0.0)
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(TOOLCHAIN_PATH "C:/keil_v5/arm/armcc/bin")  ##设置一个工具链的路径
set(CMAKE_C_COMPILER "${TOOLCHAIN_PATH}/armcc.exe")  ##设置c语言编译链,c++为CMAKE_CXX_COMPILER 
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/armasm.exe")  ##设置汇编编译工具
set(CMAKE_C_LINK_EXECUTABLE "${TOOLCHAIN_PATH}/armlink.exe") ##设置链接工具

#先配置ASM程序，再启用
enable_language(ASM) ##启用汇编语言

# set(EXECUTABLE_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)

project(demo C) 


file(GLOB_RECURSE C_FILES
        src/*.c
        src/*.h
)

set(RTE_PATH "mdk/RTE")
##比如我使用的rtthread的相关文件不想挤在一起,还可以这样
file(GLOB_RECURSE RTE_FILES
    C:/Keil_v5/ARM/PACK/ARM/CMSIS/4.5.0/Device/ARM/ARMCM0/Include/ARMCM0.h
    # C:/Keil_v5/ARM/PACK/ARM/CMSIS/4.5.0/Device/ARM/ARMCM0/Source/system_ARMCM0.c
    ${RTE_PATH}/Device/ARMCM0/startup_ARMCM0.s
    ${RTE_PATH}/Device/ARMCM0/startup_ARMCM0.c
    ${RTE_PATH}/Device/ARMCM0/system_ARMCM0.c
    )

set(SOURCE_FILES  ${C_FILES} ${RTE_FILES})

# 设置编译选项
# 从Keil5 -> Option->C/C++界面中编译控制参数复制
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -c --cpu Cortex-M0 --li -g -O0 --apcs=interwork --split_sections \
-I ${PROJECT_SOURCE_DIR}\\mdk\\RTE \
-I C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include \
-I C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\Device\\ARM\\ARMCM0\\Include \
-D__UVISION_VERSION=\"520\" -D_RTE_ -DARMCM0 \
")

# 编译参数处理：-o ".\Objects\*.o" --omf_browse ".\Objects\*.crf" --depend ".\Objects\*.d" 
# see: https://stackoverflow.com/questions/63715990/cmake-how-to-set-the-compiler-flags-that-contains-a-given-destination-path-and
# CMAKE: how to set the compiler flags that contains a given destination path and file name
#
foreach(SRC_ IN LISTS SOURCE_FILES)
    get_filename_component(SRC_BASENAME_ ${SRC_} NAME_WE)
    set_source_files_properties(${SRC_} PROPERTIES CMAKE_C_FLAGS "-o=${SRC_BASENAME_}.o --omf_browse=${SRC_BASENAME_}.crf;--depend=${SRC_BASENAME_}.d")
    get_source_file_property(SRC_PROP_ ${SRC_} CMAKE_C_FLAGS)
    message(STATUS "${SRC_}: ${SRC_PROP_}")
endforeach()

# 添加编译选项I，写法二
# include_directories(
#     ${PROJECT_SOURCE_DIR}\\mdk\\RTE
#     C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include
#     C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\Device\\ARM\\ARMCM0\\Include
# )

# 设置ARM汇编选项
set(ASM_OPTIONS  "${ASM_OPTIONS} --cpu Cortex-M0 --li -g --apcs=interwork \
-I ${PROJECT_SOURCE_DIR}\\mdk\\RTE \
-I C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\CMSIS\\Include \
-I C:\\Keil_v5\\ARM\\PACK\\ARM\\CMSIS\\4.5.0\\Device\\ARM\\ARMCM0\\Include \
--pd \"__UVISION_VERSION SETA 520\" --pd \"_RTE_ SETA 1\" --pd \"ARMCM0 SETA 1\" \
")

# 编译参数处理：--list ".\Listings\*.lst" --xref -o "*.o" --depend "*.d" 
foreach(SRC_ IN LISTS SOURCE_FILES)
    get_filename_component(SRC_BASENAME_ ${SRC_} NAME_WE)
    set_source_files_properties(${SRC_} PROPERTIES ASM_OPTIONS "--omf_browse=${SRC_BASENAME_}.lst;--depend=${SRC_BASENAME_}.d")
    get_source_file_property(SRC_PROP_ ${SRC_} ASM_OPTIONS)
    message(STATUS "${SRC_}: ${SRC_PROP_}")
endforeach()

set(CMAKE_ASM_FLAGS "${ASM_OPTIONS}")

# 设置链接参数
set(CMAKE_EXE_LINKER_FLAGS "\
--cpu Cortex-M0 \
--strict --scatter \"${PROJECT_SOURCE_DIR}\\mdk\\Objects\\demoproject.sct\" \ 
--summary_stderr --info summarysizes --map --xref --callgraph --symbols \
--info sizes --info totals --info unused --info veneers \
")

add_executable(demoproject ${SOURCE_FILES}) 

