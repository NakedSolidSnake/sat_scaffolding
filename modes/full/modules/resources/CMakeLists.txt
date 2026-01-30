add_library (resources "")

target_sources (resources
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/resources_directory.c
)

target_include_directories (resources
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)