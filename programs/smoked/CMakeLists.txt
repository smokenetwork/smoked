add_executable( smoked main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling smoked with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( SMOKE_STATIC_BUILD )
   target_link_libraries( smoked PRIVATE
      "-static-libstdc++ -static-libgcc"
      smoke_plugins
      smoke_mf_plugins
      smoke_app
      smoke_witness
      smoke_account_history
      smoke_chain
      smoke_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( SMOKE_STATIC_BUILD )
   target_link_libraries( smoked PRIVATE
      smoke_plugins
      smoke_mf_plugins
      smoke_app
      smoke_witness
      smoke_account_history
      smoke_chain
      smoke_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( SMOKE_STATIC_BUILD )

install( TARGETS
        smoked

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
