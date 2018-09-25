
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/libs)

# pthread在Linux下不是系统默认的库，所以需要手动链接
if (UNIX)
    link_libraries(pthread)
endif (UNIX)
add_subdirectory(pthread)
add_subdirectory(pthreadLock)
add_subdirectory(pthreadSync)
add_subdirectory(customString)