# just to surpress a cmake warning, probably lower versions are fine too
cmake_minimum_required(VERSION 2.6)

project(dammen)
set(CMAKE_CXX_STANDARD 17)

# dependency checking
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-2.4)

if(NOT GTKMM_FOUND)
  message(FATAL_ERROR "GTKMM not found.")
endif(NOT GTKMM_FOUND)

# public headers/include path
include_directories(${PROJECT_SOURCE_DIR}/src/include ${GTKMM_INCLUDE_DIRS})

# sources
FILE(GLOB_RECURSE SOURCES src/*.cc src/*.hh src/.ih)

add_executable(dammen ${SOURCES})
target_link_libraries(dammen ${GTKMM_LINK_LIBRARIES})

# install rules
install(TARGETS dammen DESTINATION bin)

