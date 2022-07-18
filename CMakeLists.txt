# CMake entry point
cmake_minimum_required (VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set( PROJECT_NAME sample-cpp-networking )
project( ${PROJECT_NAME} )

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	# Required for STB to work
	-DSTB_IMAGE_IMPLEMENTATION
)

add_subdirectory(boost-cmake)

set( SOURCES
    ${TARGET_DIR}/main.cpp
)

add_executable( ${PROJECT_NAME} ${SOURCES} )

target_link_libraries( ${PROJECT_NAME} PRIVATE
    Boost::boost
    Boost::system
)
