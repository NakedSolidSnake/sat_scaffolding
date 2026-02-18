add_library (workspace "")
target_sources (workspace
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/workspace.c
    ${CMAKE_CURRENT_LIST_DIR}/src/workspace_directories.c

    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/minimal_cmake_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/minimal_gitignore_template.c
)

target_include_directories (workspace
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries (workspace
    PUBLIC
    shared
)