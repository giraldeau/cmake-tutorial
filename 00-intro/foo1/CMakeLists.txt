add_library(foo1 SHARED foo1.c)
install(TARGETS foo1 DESTINATION bin)

target_compile_definitions(foo1 PRIVATE FOO1_LIBRARY)
# add_definitions() affects all targets
# add_definitions(-DFOO1_LIBRARY)