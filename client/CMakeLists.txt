cmake_minimum_required(VERSION 3.10)

project(thrift_conn_client)
set(CUR_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(CheckCXXCompilerFlag)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

aux_source_directory(${CUR_ROOT_PATH} SOURCE_FILES)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${COMMON_CPP_FILES})
target_link_libraries(${PROJECT_NAME} thrift)
