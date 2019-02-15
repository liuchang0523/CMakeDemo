if(Generate_DLL)
    
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)#设置exe文件生成路径

add_executable(${PROGRAM_NAME}Demo demo.cpp)
target_link_libraries(${PROGRAM_NAME}Demo  dll)
set_target_properties(${PROGRAM_NAME}Demo PROPERTIES
        OUTPUT_NAME Demo)#设置程序名为Demo
install(TARGETS ${PROGRAM_NAME}Demo 
        RUNTIME DESTINATION bin)#install可执行程序 
endif()