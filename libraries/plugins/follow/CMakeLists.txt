file(GLOB HEADERS "include/steemit/follow/*.hpp")

add_library( smoke_follow
             follow_plugin.cpp
             follow_api.cpp
             follow_operations.cpp
             follow_evaluators.cpp
           )

target_link_libraries( smoke_follow smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_follow
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   smoke_follow

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
