file(GLOB HEADERS "include/steemit/app/*.hpp")

add_library( smoke_app
             database_api.cpp
             api.cpp
             application.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
           )

target_link_libraries( smoke_app smoke_chain smoke_protocol smoke_tags smoke_follow smoke_witness smoke_mf_plugins fc graphene_net graphene_utilities )
target_include_directories( smoke_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   smoke_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/steemit/app" )
