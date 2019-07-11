cmake_minimum_required(VERSION 3.10)

project(thrift_conn)
set(TOP_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(CheckCXXCompilerFlag)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

if( DEFINED ENV{BOOST_HOME})
    include_directories($ENV{BOOST_HOME}/include)
    link_directories($ENV{BOOST_HOME}/lib)
endif()

CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    message("support CXX11")
    add_definitions(-std=c++11)
endif()

file(MAKE_DIRECTORY ${TOP_ROOT_PATH}/messages)
file(GLOB_RECURSE THRIFT_FILES message_file/*.thrift)
execute_process(COMMAND thrift -r -out messages --gen cpp ${THRIFT_FILES} WORKING_DIRECTORY ${TOP_ROOT_PATH})
execute_process(COMMAND rm ${TOP_ROOT_PATH}/messages/MessageService_server.skeleton.cpp)

include_directories(${TOP_ROOT_PATH}/messages)
aux_source_directory(${TOP_ROOT_PATH}/messages COMMON_CPP_FILES)

add_subdirectory(${TOP_ROOT_PATH}/server)
add_subdirectory(${TOP_ROOT_PATH}/client)
