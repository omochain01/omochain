file(GLOB HEADERS "include/omo/producer/*.hpp")

add_library( omo_producer
             producer.cpp
           )

target_link_libraries( omo_producer omo_chain omo_app )
target_include_directories( omo_producer
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   omo_producer

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
