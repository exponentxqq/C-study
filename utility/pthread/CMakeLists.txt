cmake_minimum_required(VERSION 3.10)
project(pthreadlib C)

set(CMAKE_C_STANDARD 99)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../libs)
message(${LIBRARY_OUTPUT_PATH})
set(SOURCE_FILES process.c)

include_directories(${PROJECT_SOURCE_DIR}/../../include)
link_directories(${PROJECT_SOURCE_DIR}/../../libs)

add_library(pthreadlib SHARED ${SOURCE_FILES})

#set_target_properties(PROPERTIES RUNTIME_OUTPUT_DIRECTORY> "../libs")
set_target_properties(pthreadlib PROPERTIES OUTPUT_NAME "pthreadlib")
set_target_properties(pthreadlib PROPERTIES CLEAN_DIRECT_OUTPUT 1)