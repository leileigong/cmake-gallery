cmake_minimum_required(VERSION 3.13.1)

project(import-static-lib3)

set(PkgVarPfx OPENSSL) # openSSL模块全局变量前缀OPENSSL必须大写
find_package(OpenSSL REQUIRED)

if(OpenSSL_FOUND)
    message("CMAKE_CL_64            =${CMAKE_CL_64}, ADDRESS_MODEL = ${ADDRESS_MODEL}")
    message("OPENSSL_ROOT_DIR       =${OPENSSL_ROOT_DIR}")    
    message("OPENSSL_INCLUDE_DIR    =${${PkgVarPfx}_INCLUDE_DIR}")
    message("OPENSSL_CRYPTO_LIBRARY =${${PkgVarPfx}_CRYPTO_LIBRARY}")
    message("OPENSSL_SSL_LIBRARY    =${${PkgVarPfx}_SSL_LIBRARY}")
    message("OpenSSL_LIBRARIES      =${OPENSSL_LIBRARIES}")
    add_executable(app main.c)

    if(WIN32)
    add_custom_command(TARGET app POST_BUILD
                        # 拷贝动态库文件：cmake -E copy
                        COMMAND ${CMAKE_COMMAND} -E copy
                            "${OPENSSL_ROOT_DIR}/libcrypto-1_1.dll"
                            $<TARGET_FILE_DIR:app>)
    endif(WIN32)

    set(OPENSSL_USE_STATIC_LIBS TRUE)
    target_include_directories(app PRIVATE ${${PkgVarPfx}_INCLUDE_DIR})

    # 这里的optimized配置好像并不生效，依然会链接Debug库，
    # 使用--config Release才会链接Relase库
    # target_link_libraries(app  optimized ${OPENSSL_LIBRARIES})
    # 或
    target_link_libraries(app OpenSSL::Crypto OpenSSL::SSL)
    
else(OpenSSL_FOUND)
    message(FATAL_ERROR "OpenSSL not found")
endif(OpenSSL_FOUND)





