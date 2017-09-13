find_package(Qt5Widgets)

add_library(form SHARED form.cpp)

target_link_libraries(form
    PUBLIC Qt5::Widgets
    INTERFACE Qt5::Core
)

set_property(TARGET form PROPERTY DEFINE_SYMBOL FORM_LIBRARY)
