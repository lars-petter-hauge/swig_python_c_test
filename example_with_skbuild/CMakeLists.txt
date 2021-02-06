cmake_minimum_required(VERSION 3.11.0)
project(EXAMPLE)

FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

INCLUDE_DIRECTORIES(clib/include)
SET(CMAKE_SWIG_FLAGS "")

add_subdirectory(clib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
swig_add_library( example LANGUAGE python SOURCES example.i)
SET_SOURCE_FILES_PROPERTIES(example.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(example.i PROPERTIES SWIG_FLAGS "-includeall")
set_property(SOURCE example.i PROPERTY USE_LIBRARY_INCLUDE_DIRECTORIES TRUE)
set_property(TARGET clib PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES TRUE)
swig_link_libraries(example clib)
swig_link_libraries(example ${PYTHON_LIBRARIES})

install(TARGETS _example
          LIBRARY DESTINATION lib)

add_custom_command(
        TARGET _example POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_BINARY_DIR}/example.py
                ${CMAKE_CURRENT_BINARY_DIR}/../../../example/example.py)
