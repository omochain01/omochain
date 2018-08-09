file(GLOB HEADERS "include/omo/net/*.hpp")

set(SOURCES node.cpp
            stcp_socket.cpp
            core_messages.cpp
            peer_database.cpp
            peer_connection.cpp
            message_oriented_connection.cpp)

add_library( omo_net ${SOURCES} ${HEADERS} )

target_link_libraries( omo_net
  PUBLIC fc chainbase )
target_include_directories( omo_net
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
  PRIVATE "${CMAKE_SOURCE_DIR}/libraries/chain/include"
)

if(MSVC)
  set_source_files_properties( node.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

if (USE_PCH)
  set_target_properties(omo_net PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(omo_net)
endif(USE_PCH)

install( TARGETS
   omo_net

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/omo/net" )
