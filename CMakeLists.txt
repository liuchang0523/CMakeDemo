cmake_minimum_required(VERSION 3.5)
set(Progject_Name "Test" CACHE STRING "设置工程文件名")
project(${Progject_Name} VERSION 1.0.0 LANGUAGES CXX C)#工程名

set(CMAKE_CXX_STANDARD 11) #设置C++11开启

OPTION(USE_OPENMP "使用OpenMP加速" OFF)
if (USE_OPENMP)
    find_package(OpenMP)#OpenMP
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif (USE_OPENMP)

OPTION(USE_OPENCV "使用OpenCV" OFF)
if(USE_OPENCV)#如果需要包含第三方库
    find_package( OpenCV REQUIRED )

    message( STATUS "OpenCV library status:" )
    message( STATUS "    version: ${OpenCV_VERSION}" )
    message( STATUS "    libraries: ${OpenCV_LIBS}" )
    message( STATUS "    include path: ${OpenCV_INCLUDE_DIRS}" )

    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif(USE_OPENCV)

#add子目录(要放在最后面，不然include目录不会包含)
add_subdirectory(source)
add_subdirectory(include)
add_subdirectory(demo)
