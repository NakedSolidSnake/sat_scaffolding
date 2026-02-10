add_library (adapters "")

target_sources (adapters
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/adapters_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/adapters_cmake_root_template.c
)

target_include_directories (adapters
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries (adapters
    PUBLIC
    shared
)