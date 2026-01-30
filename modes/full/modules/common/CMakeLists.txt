add_library (common "")

target_sources (common
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/common_directory.c
)

target_include_directories (common
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)