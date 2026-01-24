add_library (library "")
target_sources (library
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/library.c
    ${CMAKE_CURRENT_LIST_DIR}/src/library_directories.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/library_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/library_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/library_gitignore_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/library_include_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/library_tests_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/library_tests_cmake_template.c
)

target_include_directories (library
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)