add_library (full "")
target_sources (full
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/full.c
    ${CMAKE_CURRENT_LIST_DIR}/src/full_directories.c

    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_adapters_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_application_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_cmd_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_common_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_config_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_deploy_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_domain_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_resources_directory.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/full_tools_directory.c

    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/full_main_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/full_cmake_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/full_gitignore_template.c
)

target_include_directories (full
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)