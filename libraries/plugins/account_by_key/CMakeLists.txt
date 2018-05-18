file(GLOB HEADERS "include/steemit/account_by_key/*.hpp")

add_library( smoke_account_by_key
             account_by_key_plugin.cpp
             account_by_key_api.cpp
           )

target_link_libraries( smoke_account_by_key smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_account_by_key
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   smoke_account_by_key

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
