cmake_minimum_required (VERSION 3.0)
project (UDPReader)
# The version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

find_package(PkgConfig REQUIRED)
if(PKG_CONFIG_FOUND)
	message([STATUS] "PkgConfig was found at ${PKG_CONFIG_EXECUTABLE}")
endif()

# Extend the find_package search path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
	)
	
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# should we use our own math functions?
#option (USE_MYMATH
#	"Use tutorial provided math implementation" ON)

#add the MathFunctions library?
#
#if (USE_MYMATH)
#	include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
#	add_subdirectory(MathFunctions)
#	set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
#endif (USE_MYMATH)

#Find Allegro
find_package(ALLEGRO)

if(ALLEGRO_FOUND)
	include_directories(${ALLEGRO_INCLUDE_DIRS})
	list(APPEND ${EXTRA_LIBS} ${ALLEGRO_LIBRARY})
endif()
	
# add the executable
add_executable (Tutorial reader.cpp)
target_link_libraries (Tutorial ${EXTRA_LIBS} PkgConfig::PC_ALLEGRO)
