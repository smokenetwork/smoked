file(GLOB HEADERS "include/steemit/account_statistics/*.hpp")

add_library( smoke_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( smoke_account_statistics smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   smoke_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)