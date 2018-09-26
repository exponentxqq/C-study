cmake_minimum_required(VERSION 3.10)
project(Cprogram C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(server)
add_subdirectory(utility)

link_directories(libs)
include_directories(include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(test main/test.c)

link_libraries(pthreadlib)
add_executable(pthread main/pthread.c)
target_link_libraries(pthread pthreadlib)

link_libraries(pthreadLocklib)
add_executable(pthreadLock main/pthreadLock.c)
target_link_libraries(pthreadLock pthreadLocklib)

link_libraries(pthreadSyncLib)
add_executable(pthreadSync main/pthreadSync.c)
target_link_libraries(pthreadSync pthreadSyncLib)

link_libraries(customStringlib)
add_executable(string main/string.c)
target_link_libraries(string customStringlib)