cmake_minimum_required(VERSION 3.10)
project(pthreadSyncLib C)

set(CMAKE_C_STANDARD 99)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../libs)
message(${LIBRARY_OUTPUT_PATH})
set(SOURCE_FILES pthreadSync.c)

include_directories(${PROJECT_SOURCE_DIR}/../../include)
link_directories(${PROJECT_SOURCE_DIR}/../../libs)

add_library(pthreadSyncLib SHARED ${SOURCE_FILES})

#set_target_properties(PROPERTIES RUNTIME_OUTPUT_DIRECTORY> "../libs")
set_target_properties(pthreadSyncLib PROPERTIES OUTPUT_NAME "pthreadSyncLib")
set_target_properties(pthreadSyncLib PROPERTIES CLEAN_DIRECT_OUTPUT 1)