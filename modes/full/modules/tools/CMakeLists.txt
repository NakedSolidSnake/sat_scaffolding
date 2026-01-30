add_library (tools "")

target_sources (tools
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/tools_directory.c
)

target_include_directories (tools
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)