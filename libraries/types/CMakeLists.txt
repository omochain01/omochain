file(GLOB HEADERS "include/omo/types/*.hpp")

add_library( omo_types
             Asset.cpp
             PublicKey.cpp
             TypeParser.cpp
             native.cpp
             ${HEADERS}
             "${CMAKE_CURRENT_SOURCE_DIR}/include/omo/types/generated.hpp"
             types.omo
             )
target_include_directories( omo_types PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_link_libraries( omo_types omo_utilities fc )

add_executable( type_generator type_generator.cpp TypeParser.cpp native.cpp )
target_include_directories( type_generator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_link_libraries( type_generator omo_utilities fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS}  )

add_custom_command( OUTPUT  "${CMAKE_CURRENT_SOURCE_DIR}/include/omo/types/generated.hpp"
                    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/type_generator ${CMAKE_CURRENT_SOURCE_DIR}/types.omo ${CMAKE_CURRENT_SOURCE_DIR}/include/omo/types/generated.hpp
                    DEPENDS types.omo type_generator )

