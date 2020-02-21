file(GLOB HEADERS "include/smoke/witness/*.hpp")

add_library( smoke_witness
             witness_plugin.cpp
             witness_evaluators.cpp
             witness_operations.cpp
             simple_daily_bandwidth_limit.cpp
           )

target_link_libraries( smoke_witness smoke_chain smoke_protocol smoke_app )
target_include_directories( smoke_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
        smoke_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
