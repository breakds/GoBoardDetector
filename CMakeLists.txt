CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(GoBoardDetector)

SET(CMAKE_CXX_COMPILER_INIT "c++")

MESSAGE(STATUS "Project Name:           ${PROJECT_NAME}")
MESSAGE(STATUS "Project Source Dir:     ${PROJECT_SOURCE_DIR}")
MESSAGE(STATUS "Kernel:                 ${CMAKE_SYSTEM}")
EXECUTE_PROCESS(COMMAND hostname OUTPUT_VARIABLE HOSTNAME)
MESSAGE(STATUS "Hostname:               ${HOSTNAME}")
MESSAGE(STATUS "Build Type:             ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "GCC:                    ${CMAKE_CXX_COMPILER}")

# option (BUILD_UNITTEST "build executables in purpose of unittest." ON)
FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES("../")

SET(CMAKE_CXX_FLAGS "${OPENCV_FLAGS} -Wall -Wextra -Wno-non-virtual-dtor -std=c++0x")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -DNDEBUG -O3 -fopenmp")
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -fopenmp")
SET(CMAKE_CXX_FLAGS_GPROF "-O1 -pg")

ADD_EXECUTABLE(analyzer analyzer.cc)
TARGET_LINK_LIBRARIES(analyzer ${OpenCV_LIBS})


