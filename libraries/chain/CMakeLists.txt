
file(GLOB HEADERS "include/omo/chain/*.hpp")
file(GLOB PROTOCOL_HEADERS "include/omo/chain/protocol/*.hpp")

## SORT .cpp by most likely to change / break compile
add_library( omo_chain
             database.cpp
             fork_database.cpp

             protocol/types.cpp
             protocol/transaction.cpp
             protocol/block.cpp

             genesis_state.cpp
             get_config.cpp

             block_log.cpp

             ${HEADERS}
             ${PROTOCOL_HEADERS}
           )

target_link_libraries( omo_chain fc chainbase )
target_include_directories( omo_chain
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include" )

if(MSVC)
  set_source_files_properties( db_init.cpp db_block.cpp database.cpp block_log.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   omo_chain

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/omo/chain" )
INSTALL( FILES ${PROTOCOL_HEADERS} DESTINATION "include/omo/chain/protocol" )
