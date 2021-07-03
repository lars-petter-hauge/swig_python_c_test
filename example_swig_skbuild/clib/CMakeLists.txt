PROJECT(example)

IF (APPLE)
  set(INSTALL_NAME_DIR @executable_path/../lib)
  set(CMAKE_MACOSX_RPATH 1)
ENDIF (APPLE)

# Sets for output directory for executables and libraries.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

file(GLOB EXAMPLE_LIB RELATIVE ${PROJECT_SOURCE_DIR} src/*.c)

add_library(clib STATIC ${EXAMPLE_LIB})
target_include_directories(clib PUBLIC ${PROJECT_SOURCE_DIR}/include)

install(TARGETS clib
          LIBRARY DESTINATION lib
          PUBLIC_HEADER DESTINATION include)
