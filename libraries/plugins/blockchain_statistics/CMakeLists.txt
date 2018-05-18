file(GLOB HEADERS "include/smoke/blockchain_statistics/*.hpp")

add_library( smoke_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( smoke_blockchain_statistics smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
        smoke_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)