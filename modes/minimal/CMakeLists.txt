add_library (minimal "")
target_sources (minimal
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/minimal.c
    ${CMAKE_CURRENT_LIST_DIR}/src/minimal_directories.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/minimal_main_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/minimal_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/minimal_gitignore_template.c
)

target_include_directories (minimal
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)