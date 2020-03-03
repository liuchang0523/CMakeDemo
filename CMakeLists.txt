cmake_minimum_required(VERSION 3.5)
set(Progject_Name "Test" CACHE STRING "设置工程文件名")
project(${Progject_Name} VERSION 1.1.0 LANGUAGES CXX C)#工程名

#设置默认install位置
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "Installation Directory" FORCE)
message(STATUS "CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}")

set(CMAKE_CXX_STANDARD 11) #设置C++11开启

OPTION(USE_OPENMP "使用OpenMP加速" OFF)
if (USE_OPENMP)
    find_package(OpenMP)#OpenMP
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif (USE_OPENMP)

OPTION(USE_OPENCV "使用OpenCV" ON)
if(USE_OPENCV)#如果需要包含第三方库
    find_package( OpenCV REQUIRED )

    message( STATUS "OpenCV library status:" )
    message( STATUS "    version: ${OpenCV_VERSION}" )
    message( STATUS "    libraries: ${OpenCV_LIBS}" )
    message( STATUS "    include path: ${OpenCV_INCLUDE_DIRS}" )

    include_directories( ${OpenCV_INCLUDE_DIRS} )
endif(USE_OPENCV)

OPTION(USE_OPENCV "使用Boost" ON)
if(USE_BOOST)#如果需要包含Boost
find_package(Boost REQUIRED filesystem) #PATHS E:/3rdParty/install)
include_directories(${Boost_INCLUDE_DIRS})
endif(USE_BOOST)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)#设置静态库文件生成路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)#设置动态库文件生成路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)#设置exe文件生成路径

#add子目录(要放在最后面，不然include目录不会包含)
add_subdirectory(source)
add_subdirectory(include)
add_subdirectory(demo)
