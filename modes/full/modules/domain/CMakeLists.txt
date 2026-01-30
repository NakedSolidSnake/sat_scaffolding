add_library (domain "")

target_sources (domain
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/domain_directory.c
)

target_include_directories (domain
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)