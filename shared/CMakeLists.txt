add_library (shared "")

target_sources (shared
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/shared.c
)

target_include_directories (shared
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)