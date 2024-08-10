add_library(engine_sources STATIC "")

target_sources(engine_sources PRIVATE 
    game.cpp
    graphics.cpp
)

target_include_directories(engine_sources PRIVATE .)

target_link_libraries(engine_sources 
    PRIVATE 
        Engine::CompileOptions
        Engine::Headers
        Engine::BackendHeaders
)

set_target_properties(engine_sources PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CLANG_TIDY>
)

add_library(Engine::Sources ALIAS engine_sources)
