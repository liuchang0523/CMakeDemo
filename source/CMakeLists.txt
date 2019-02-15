set(PROGRAM_NAME ${PROJECT_NAME})#设置程序名

FILE(GLOB SRC_FILES "*.cpp")#源文件
FILE(GLOB HEAD_FILES "*.h")#头文件
FILE(GLOB RC_FILES "*.rc")#资源文件


#生成资源文件
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.rc.in
        ${CMAKE_CURRENT_SOURCE_DIR}/version.rc
        NEWLINE_STYLE UNIX)
#生成版本号头文件
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
        ${CMAKE_CURRENT_SOURCE_DIR}/version.h
        NEWLINE_STYLE UNIX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)#设置exe文件生成路径

add_executable(exe ${SRC_FILES} ${HEAD_FILES} ${RC_FILES})
set_target_properties(exe PROPERTIES
        OUTPUT_NAME ${PROGRAM_NAME})#设置程序名为Project的名字
install(TARGETS exe 
		RUNTIME DESTINATION bin)#install可执行程序 

if(USE_OPENCV)#如果需要包含第三方库
    target_link_libraries(exe ${OpenCV_LIBS})
endif()

OPTION(Generate_DLL "生成动态库" OFF)
if(Generate_DLL)
    add_library(dll SHARED ${SRC_FILES} ${HEAD_FILES} ${RC_FILES})
    set_target_properties(dll PROPERTIES
        OUTPUT_NAME ${PROGRAM_NAME}Shared)#设置程序名为Project的名字
    install(TARGETS dll
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

if(USE_OPENCV)
    target_link_libraries(dll ${OpenCV_LIBS})
endif()
endif(Generate_DLL)

OPTION(Install_DLL "拷贝安装第三方库" OFF)
if(Install_DLL)
    FILE(GLOB 3rd_FILES "${PROJECT_BINARY_DIR}/bin/Release/*.dll")#源文件
    if(3rd_FILES)
        message(STATUS ${3rd_FILES})
        install(FILES ${3rd_FILES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    endif()
endif(Install_DLL)