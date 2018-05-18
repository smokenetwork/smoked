file(GLOB HEADERS "include/smoke/market_history/*.hpp")

add_library( smoke_market_history
             market_history_plugin.cpp
             market_history_api.cpp
           )

target_link_libraries( smoke_market_history smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   smoke_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)