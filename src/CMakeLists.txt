add_executable (sat_scaffolding "")
target_sources (sat_scaffolding
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/main.c
)
target_include_directories (sat_scaffolding
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries (sat_scaffolding
    PRIVATE
    minimal
    library
    full
)

install (TARGETS sat_scaffolding DESTINATION ${CMAKE_INSTALL_BINDIR})