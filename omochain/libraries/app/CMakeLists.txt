file(GLOB HEADERS "include/omo/app/*.hpp")
file(GLOB EGENESIS_HEADERS "../egenesis/include/omo/app/*.hpp")

add_library( omo_app
             api.cpp
             application.cpp
             plugin.cpp
             ${HEADERS}
             ${EGENESIS_HEADERS}
           )

# need to link omo_debug_producer because plugins aren't sufficiently isolated #246
target_link_libraries( omo_app omo_chain fc omo_net omo_utilities omo_debug_producer )
target_include_directories( omo_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            "${CMAKE_CURRENT_SOURCE_DIR}/../egenesis/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   omo_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/omo/app" )
