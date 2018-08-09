file(GLOB HEADERS "include/omo/debug_producer/*.hpp")

add_library( omo_debug_producer
             debug_api.cpp
             debug_producer.cpp
           )

target_link_libraries( omo_debug_producer omo_chain omo_app )
target_include_directories( omo_debug_producer
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   omo_debug_producer

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
