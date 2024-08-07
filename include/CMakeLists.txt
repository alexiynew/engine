add_library(engine_headers INTERFACE)

target_include_directories(engine_headers INTERFACE .)

target_sources(engine_headers INTERFACE 
    engine/game.hpp
    engine/graphics.hpp
)

add_library(Engine::Headers ALIAS engine_headers)
