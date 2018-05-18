file(GLOB HEADERS "include/steemit/plugins/raw_block/*.hpp")

add_library( smoke_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( smoke_raw_block smoke_app smoke_chain smoke_protocol fc )
target_include_directories( smoke_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
