add_subdirectory (modules)


add_library (full "")
target_sources (full
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/full.c

    ${CMAKE_CURRENT_LIST_DIR}/src/directories/root/full_root_directories.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/root/full_source_directories.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/root/full_resources_directories.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/root/full_tools_directories.c

    ${CMAKE_CURRENT_LIST_DIR}/src/directories/adapters/full_adapters_directories.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/application/full_application_directories.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/common/full_common_directories.c
    ${CMAKE_CURRENT_LIST_DIR}/src/directories/domain/full_domain_directories.c

    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/readme_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/dockerfile_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/docker_compose_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/cmake_template.c
    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/gitignore_template.c

    # ${CMAKE_CURRENT_LIST_DIR}/src/templates/cmake_source_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_readme_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_dockerfile_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_docker_compose_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_gitignore_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_cmake_source_template.c
)

target_include_directories (full
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${CMAKE_CURRENT_LIST_DIR}/include/directories/root
    ${CMAKE_CURRENT_LIST_DIR}/include/directories/adapters
    ${CMAKE_CURRENT_LIST_DIR}/include/directories/application
    ${CMAKE_CURRENT_LIST_DIR}/include/directories/common
    ${CMAKE_CURRENT_LIST_DIR}/include/directories/domain
    
    ${CMAKE_CURRENT_LIST_DIR}/include/templates
    ${CMAKE_CURRENT_LIST_DIR}/include/templates/root
)

target_link_libraries (full 
    PUBLIC
    adapters
    # application
    # cmd
    # common
    deploy
    # domain
    resources
    tools
)