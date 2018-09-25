set(SOURCE_FILES customString.c)

add_library(customStringlib SHARED ${SOURCE_FILES})

set_target_properties(customStringlib PROPERTIES OUTPUT_NAME "customStringlib")
set_target_properties(customStringlib PROPERTIES CLEAN_DIRECT_OUTPUT 1)