set(SOURCE_FILES process.c)

add_library(pthreadlib SHARED ${SOURCE_FILES})

set_target_properties(pthreadlib PROPERTIES OUTPUT_NAME "pthreadlib")
set_target_properties(pthreadlib PROPERTIES CLEAN_DIRECT_OUTPUT 1)