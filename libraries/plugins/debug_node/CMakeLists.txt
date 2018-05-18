file(GLOB HEADERS "include/steemit/plugins/debug_node/*.hpp")

add_library( smoke_debug_node
             ${HEADERS}
             debug_node_plugin.cpp
             debug_node_api.cpp
           )

target_link_libraries( smoke_debug_node smoke_app smoke_chain smoke_protocol fc )
target_include_directories( smoke_debug_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS smoke_debug_node
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
       )
INSTALL( FILES ${HEADERS} DESTINATION "include/steemit/plugins/debug_node" )
