add_library(engine_sources STATIC "")

target_sources(engine_sources PRIVATE 
    game.cpp
    graphics.cpp
)

target_include_directories(engine_sources PRIVATE .)

target_link_libraries(engine_sources PRIVATE Engine::CompileOptions)
target_link_libraries(engine_sources PRIVATE Engine::Headers)
target_link_libraries(engine_sources PRIVATE Engine::BackendHeaders)

add_library(Engine::Sources ALIAS engine_sources)
