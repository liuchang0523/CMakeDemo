FILE(GLOB HEAD_FILES "*.h")#头文件
FILE(GLOB RC_FILES "*.rc")#资源文件

set(HEAD_FILES ${HEAD_FILES} CACHE INTERNAL "头文件")
set(RC_FILES ${RC_FILES} CACHE INTERNAL "资源文件")

#生成资源文件
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
        ${CMAKE_CURRENT_SOURCE_DIR}/version.rc
        NEWLINE_STYLE UNIX)
#生成版本号头文件
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
        ${CMAKE_CURRENT_SOURCE_DIR}/version.h
        NEWLINE_STYLE UNIX)