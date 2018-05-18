file(GLOB HEADERS "include/smoke/private_message/*.hpp")

add_library( smoke_private_message
             private_message_plugin.cpp
           )

target_link_libraries( smoke_private_message smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   smoke_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
