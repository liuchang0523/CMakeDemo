OPTION(Generate_STATIC_DLL "生成动态库" ON)
if(Generate_STATIC_DLL)
    add_library(dll_static STATIC mul.cpp ${HEAD_FILES} ${RC_FILES})
    target_compile_definitions(dll_static PRIVATE dll_EXPORTS)
    set_target_properties(dll_static PROPERTIES
        OUTPUT_NAME ${PROGRAM_NAME}Static)#设置程序名为Project的名字
IF (WIN32)
IF(CMAKE_CL_64)
    install(TARGETS dll_static
    ARCHIVE DESTINATION lib/win64
    LIBRARY DESTINATION lib/win64
    RUNTIME DESTINATION bin/win64)
ELSE(CMAKE_CL_64)
    install(TARGETS dll_static
    ARCHIVE DESTINATION lib/x86
    LIBRARY DESTINATION lib/x86
    RUNTIME DESTINATION bin/x86)
ENDIF(CMAKE_CL_64)
ENDIF(WIN32)

if(USE_OPENCV)
    target_link_libraries(dll_shared ${OpenCV_LIBS})
endif(USE_OPENCV)
endif(Generate_STATIC_DLL)