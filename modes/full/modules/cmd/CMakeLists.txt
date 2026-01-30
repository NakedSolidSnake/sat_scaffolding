add_library (cmd "")

target_sources (cmd
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/cmd_directory.c
)

target_include_directories (cmd
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)