set(SOURCE_FILES pthreadlock.c)

add_library(pthreadLocklib SHARED ${SOURCE_FILES})

set_target_properties(pthreadLocklib PROPERTIES OUTPUT_NAME "pthreadLocklib")
set_target_properties(pthreadLocklib PROPERTIES CLEAN_DIRECT_OUTPUT 1)