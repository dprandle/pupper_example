cmake_minimum_required(VERSION 2.8)

project(pupper_example)

# Set the source directories
set(PUPPER_SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Set the include directory
set(PUPPER_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(SRC_FILES
${PUPPER_SRC_DIR}/binary_file_pupper.cpp
${PUPPER_SRC_DIR}/main.cpp
${PUPPER_SRC_DIR}/math_structs.cpp
${PUPPER_SRC_DIR}/derived_obj_a.cpp
${PUPPER_SRC_DIR}/obj_a.cpp
${PUPPER_SRC_DIR}/obj_a_container.cpp
${PUPPER_SRC_DIR}/pupper.cpp
${PUPPER_SRC_DIR}/text_file_pupper.cpp
)

set(HEADER_FILES 
${PUPPER_INCLUDE_DIR}/binary_file_pupper.h
${PUPPER_INCLUDE_DIR}/derived_obj_a.h
${PUPPER_INCLUDE_DIR}/math_structs.h
${PUPPER_INCLUDE_DIR}/obj_a.h
${PUPPER_INCLUDE_DIR}/obj_a_container.h
${PUPPER_INCLUDE_DIR}/pupper.h
${PUPPER_INCLUDE_DIR}/text_file_pupper.h
)

include_directories(
${PUPPER_INCLUDE_DIR}
)

if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fms-extensions")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
elseif (WIN32)
  set(LINKER_ARGS "/WX /NODEFAULTLIB:MSVCRT /NODEFAULTLIB:LIBCMT")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${LINKER_ARGS}" )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MP")
endif()

set(CMAKE_DEBUG_POSTFIX d)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${PLATFORM})

add_custom_target(headers SOURCES ${HEADER_FILES})
add_executable(pupper_example ${SRC_FILES})
set_target_properties(pupper_example PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

