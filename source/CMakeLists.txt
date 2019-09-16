set(PROGRAM_NAME ${PROJECT_NAME})#设置程序名

FILE(GLOB SRC_FILES "*.cpp")#源文件
add_subdirectory(version)#版本相关文件

add_executable(exe ${SRC_FILES} ${HEAD_FILES} ${RC_FILES})
set_target_properties(exe PROPERTIES
        OUTPUT_NAME ${PROGRAM_NAME})#设置程序名为Project的名字
install(TARGETS exe 
		RUNTIME DESTINATION bin)#install可执行程序 

if(USE_OPENCV)#如果需要包含第三方库
    target_link_libraries(exe ${OpenCV_LIBS})
endif()

OPTION(Generate_DLL "生成动态库" ON)
if(Generate_DLL)
    add_library(dll SHARED ${SRC_FILES} ${HEAD_FILES} ${RC_FILES})
    set_target_properties(dll PROPERTIES
        OUTPUT_NAME ${PROGRAM_NAME}Shared)#设置程序名为Project的名字
IF (WIN32)
IF(CMAKE_CL_64)
    install(TARGETS dll
    ARCHIVE DESTINATION lib/win64
    LIBRARY DESTINATION lib/win64
    RUNTIME DESTINATION bin/win64)
ELSE(CMAKE_CL_64)
    install(TARGETS dll
    ARCHIVE DESTINATION lib/x86
    LIBRARY DESTINATION lib/x86
    RUNTIME DESTINATION bin/x86)
ENDIF(CMAKE_CL_64)
ENDIF(WIN32)

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