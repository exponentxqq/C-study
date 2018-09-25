set(SOURCE_FILES pthreadSync.c)

add_library(pthreadSyncLib SHARED ${SOURCE_FILES})

set_target_properties(pthreadSyncLib PROPERTIES OUTPUT_NAME "pthreadSyncLib")
set_target_properties(pthreadSyncLib PROPERTIES CLEAN_DIRECT_OUTPUT 1)