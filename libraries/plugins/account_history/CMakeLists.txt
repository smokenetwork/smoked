file(GLOB HEADERS "include/steemit/account_history/*.hpp")

add_library( smoke_account_history
             account_history_plugin.cpp
           )

target_link_libraries( smoke_account_history smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   smoke_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
