if(Generate_STATIC_DLL AND NOT Generate_SHARED_DLL)
add_executable(${PROGRAM_NAME}Demo demo_static.cpp ${RC_FILES})
target_link_libraries(${PROGRAM_NAME}Demo  dll_static)
set_target_properties(${PROGRAM_NAME}Demo PROPERTIES
        OUTPUT_NAME Demo)#设置程序名为Demo
IF (WIN32)
IF(CMAKE_CL_64)
    install(TARGETS ${PROGRAM_NAME}Demo 
        RUNTIME DESTINATION bin/win64)#install可执行程序 
ELSE(CMAKE_CL_64)
    install(TARGETS ${PROGRAM_NAME}Demo 
    RUNTIME DESTINATION bin/x86)#install可执行程序 
ENDIF(CMAKE_CL_64)
ENDIF(WIN32)
endif(Generate_STATIC_DLL AND NOT Generate_SHARED_DLL)

if(Generate_SHARED_DLL AND NOT Generate_STATIC_DLL)
add_executable(${PROGRAM_NAME}Demo demo_shared.cpp ${RC_FILES})
target_link_libraries(${PROGRAM_NAME}Demo  dll_shared)
set_target_properties(${PROGRAM_NAME}Demo PROPERTIES
        OUTPUT_NAME Demo)#设置程序名为Demo
IF (WIN32)
IF(CMAKE_CL_64)
    install(TARGETS ${PROGRAM_NAME}Demo 
        RUNTIME DESTINATION bin/win64)#install可执行程序 
ELSE(CMAKE_CL_64)
    install(TARGETS ${PROGRAM_NAME}Demo 
    RUNTIME DESTINATION bin/x86)#install可执行程序 
ENDIF(CMAKE_CL_64)
ENDIF(WIN32)
endif(Generate_SHARED_DLL AND NOT Generate_STATIC_DLL)

if(Generate_SHARED_DLL AND Generate_STATIC_DLL)
add_executable(${PROGRAM_NAME}Demo demo_shared_static.cpp ${RC_FILES})
target_link_libraries(${PROGRAM_NAME}Demo  dll_shared dll_static)
set_target_properties(${PROGRAM_NAME}Demo PROPERTIES
        OUTPUT_NAME Demo)#设置程序名为Demo
IF (WIN32)
IF(CMAKE_CL_64)
    install(TARGETS ${PROGRAM_NAME}Demo 
        RUNTIME DESTINATION bin/win64)#install可执行程序 
ELSE(CMAKE_CL_64)
    install(TARGETS ${PROGRAM_NAME}Demo 
    RUNTIME DESTINATION bin/x86)#install可执行程序 
ENDIF(CMAKE_CL_64)
ENDIF(WIN32)
endif(Generate_SHARED_DLL AND Generate_STATIC_DLL)