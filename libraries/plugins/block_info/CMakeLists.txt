file(GLOB HEADERS "include/steemit/plugins/block_info/*.hpp")

add_library( smoke_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( smoke_block_info smoke_app smoke_chain smoke_protocol fc )
target_include_directories( smoke_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
