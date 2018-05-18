file(GLOB HEADERS "include/smoke/delayed_node/*.hpp")

add_library( smoke_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( smoke_delayed_node smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   smoke_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
