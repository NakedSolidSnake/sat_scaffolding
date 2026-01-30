add_library (application "")

target_sources (application
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/application_directory.c
)

target_include_directories (application
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)