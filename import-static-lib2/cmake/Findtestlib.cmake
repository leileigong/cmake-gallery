# 设置头文件查找路径
find_path(testlib_INCLUDE_DIR
    NAMES array.h
    PATHS "D:/Program Files (x86)/testlib/include/" /usr/local/include/
)

# 设置库文件查找路径
find_library(testlib_LIBRARY
    NAMES testlib # 也可以是具体文件名
    PATHS "D:/Program Files (x86)/testlib/lib/" /usr/local/lib/
)

if(testlib_INCLUDE_DIR AND testlib_LIBRARY)  # `AND`必须大写
    set(testlib_FOUND TRUE)
endif(testlib_INCLUDE_DIR AND testlib_LIBRARY)