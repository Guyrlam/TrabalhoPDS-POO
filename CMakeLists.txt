cmake_minimum_required(VERSION 3.5)
project(MeuProjeto CXX)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# Directories
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(BUILD_DIR build)
set(BIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/../bin)  # Define o diretório bin no nível acima de build

# Files
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")
set(OBJ_FILES "")
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(SRC_FILENAME ${SRC_FILE} NAME)
    string(REPLACE ".cpp" ".o" OBJ_FILE "${SRC_FILENAME}")
    list(APPEND OBJ_FILES "${BUILD_DIR}/${OBJ_FILE}")
endforeach()

# Targets
add_executable(main ${SRC_FILES})
target_include_directories(main PRIVATE ${INCLUDE_DIR})

# Set output directories
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${BIN_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR})

# Clean
add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BUILD_DIR}
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BIN_DIR}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})