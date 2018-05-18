file(GLOB HEADERS "include/steemit/tags/*.hpp")

add_library( smoke_tags
             tags_plugin.cpp )

target_link_libraries( smoke_tags smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_tags
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
        smoke_tags

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
