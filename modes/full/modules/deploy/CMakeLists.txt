add_library (deploy "")

target_sources (deploy
    PRIVATE

    ${CMAKE_CURRENT_LIST_DIR}/src/deploy_directory.c
)

target_include_directories (deploy
    PUBLIC

    ${CMAKE_CURRENT_LIST_DIR}/include
)