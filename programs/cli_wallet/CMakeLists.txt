add_executable( cli_wallet main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling cli_wallet with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( STEEM_STATIC_BUILD )
   # I don't know why smoke_app is required twice in the following line, I just know the linker breaks if it isn't.
   target_link_libraries( cli_wallet PRIVATE
                          "-static-libstdc++ -static-libgcc -lreadline"
           smoke_app graphene_net smoke_chain smoke_protocol graphene_utilities smoke_wallet smoke_private_message smoke_app smoke_follow fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
else( STEEM_STATIC_BUILD )
   target_link_libraries( cli_wallet PRIVATE
           smoke_app graphene_net smoke_chain smoke_protocol graphene_utilities smoke_wallet smoke_private_message smoke_app smoke_follow fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
endif( STEEM_STATIC_BUILD )

if(MSVC)
  set_source_files_properties( main.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   cli_wallet

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
