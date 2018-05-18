file(GLOB HEADERS "include/steemit/plugins/auth_util/*.hpp")

add_library( smoke_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( smoke_auth_util smoke_app smoke_chain smoke_protocol fc )
target_include_directories( smoke_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
