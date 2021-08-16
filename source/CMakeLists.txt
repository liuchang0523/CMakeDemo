include_directories(version)
add_subdirectory(version)
add_subdirectory(add)
add_subdirectory(mul)

# set(PROGRAM_NAME ${PROJECT_NAME})#设置程序名

# add_executable(exe main.cpp ${HEAD_FILES} ${RC_FILES})
# set_target_properties(exe PROPERTIES
#         OUTPUT_NAME ${PROGRAM_NAME})#设置程序名为Project的名字
# install(TARGETS exe 
# 		RUNTIME DESTINATION bin)#install可执行程序 
# target_link_libraries(exe ${Boost_LIBRARIES})

# if(USE_OPENCV)#如果需要包含第三方库
#     target_link_libraries(exe ${OpenCV_LIBS})
# endif()

# if(USE_Boost_filesystem)#如果需要包含Boost
# target_link_libraries(exe ${Boost_LIBRARIES})
# endif(USE_Boost_filesystem)

# OPTION(Generate_SHARED_DLL "生成动态库" ON)
# if(Generate_SHARED_DLL)
#     add_library(dll_shared SHARED add.cpp ${HEAD_FILES} ${RC_FILES})
#     target_compile_definitions(dll_shared PRIVATE dll_EXPORTS)
#     set_target_properties(dll_shared PROPERTIES
#         OUTPUT_NAME ${PROGRAM_NAME}Shared)#设置程序名为Project的名字
# IF (WIN32)
# IF(CMAKE_CL_64)
#     install(TARGETS dll_shared
#     ARCHIVE DESTINATION lib/win64
#     LIBRARY DESTINATION lib/win64
#     RUNTIME DESTINATION bin/win64)
# ELSE(CMAKE_CL_64)
#     install(TARGETS dll_shared
#     ARCHIVE DESTINATION lib/x86
#     LIBRARY DESTINATION lib/x86
#     RUNTIME DESTINATION bin/x86)
# ENDIF(CMAKE_CL_64)
# ENDIF(WIN32)

# if(USE_OPENCV)
#     target_link_libraries(dll_shared ${OpenCV_LIBS})
# endif(USE_OPENCV)
# endif(Generate_SHARED_DLL)

# OPTION(Generate_STATIC_DLL "生成动态库" ON)
# if(Generate_STATIC_DLL)
#     add_library(dll_static STATIC mul.cpp ${HEAD_FILES} ${RC_FILES})
#     target_compile_definitions(dll_static PRIVATE dll_EXPORTS)
#     set_target_properties(dll_static PROPERTIES
#         OUTPUT_NAME ${PROGRAM_NAME}Static)#设置程序名为Project的名字
# IF (WIN32)
# IF(CMAKE_CL_64)
#     install(TARGETS dll_static
#     ARCHIVE DESTINATION lib/win64
#     LIBRARY DESTINATION lib/win64
#     RUNTIME DESTINATION bin/win64)
# ELSE(CMAKE_CL_64)
#     install(TARGETS dll_static
#     ARCHIVE DESTINATION lib/x86
#     LIBRARY DESTINATION lib/x86
#     RUNTIME DESTINATION bin/x86)
# ENDIF(CMAKE_CL_64)
# ENDIF(WIN32)

# if(USE_OPENCV)
#     target_link_libraries(dll_shared ${OpenCV_LIBS})
# endif(USE_OPENCV)
# endif(Generate_STATIC_DLL)

# OPTION(Install_DLL "拷贝安装第三方库" OFF)
# if(Install_DLL)
#     FILE(GLOB 3rd_FILES "${PROJECT_BINARY_DIR}/bin/Release/*.dll")#源文件
#     if(3rd_FILES)
#         message(STATUS ${3rd_FILES})
#         install(FILES ${3rd_FILES} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#     endif()
# endif(Install_DLL)