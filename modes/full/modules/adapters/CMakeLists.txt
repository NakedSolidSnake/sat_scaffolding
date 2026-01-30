add_library (adapters "")

target_sources (adapters
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/adapters_directory.c
)

target_include_directories (adapters
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)