if(Generate_DLL)
add_executable(${PROGRAM_NAME}Demo demo.cpp ${RC_FILES})
target_link_libraries(${PROGRAM_NAME}Demo  dll)
set_target_properties(${PROGRAM_NAME}Demo PROPERTIES
        OUTPUT_NAME Demo)#设置程序名为Demo
install(TARGETS ${PROGRAM_NAME}Demo 
        RUNTIME DESTINATION bin)#install可执行程序 
endif()