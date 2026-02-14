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

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_readme_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_dockerfile_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_docker_compose_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_gitignore_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/root/full_root_cmake_source_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_config_header_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_config_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_config_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_factory_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_ports_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_repositories_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/adapters/full_adapters_cmake_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_entities_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_entities_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_services_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_services_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_services_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_value_objects_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_value_objects_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_ports_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_tests_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/domain/domain_tests_source_template.c


    ${CMAKE_CURRENT_LIST_DIR}/src/templates/common/common_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/common/common_source_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/cmd/full_cmd_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/cmd/full_cmd_main_template.c

    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_context_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_context_header_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_context_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_services_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_services_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_tests_cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/templates/application/application_tests_source_template.c

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
    ${CMAKE_CURRENT_LIST_DIR}/include/templates/adapters
    ${CMAKE_CURRENT_LIST_DIR}/include/templates/domain
    ${CMAKE_CURRENT_LIST_DIR}/include/templates/common
    ${CMAKE_CURRENT_LIST_DIR}/include/templates/cmd
    ${CMAKE_CURRENT_LIST_DIR}/include/templates/application

)

target_link_libraries (full 
    PUBLIC
    shared
)