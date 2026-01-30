add_library (config "")

target_sources (config
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/config_directory.c
)

target_include_directories (config
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)