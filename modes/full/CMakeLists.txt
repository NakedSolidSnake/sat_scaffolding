add_subdirectory (modules)


add_library (full "")
target_sources (full
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/full.c
    ${CMAKE_CURRENT_LIST_DIR}/src/full_directories.c
)

target_include_directories (full
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries (full 
    PUBLIC
    adapters
    application
    cmd
    common
    config
    deploy
    domain
    resources
    tools
)