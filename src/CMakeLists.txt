add_library(engine_sources OBJECT)

target_sources(engine_sources
    PRIVATE 
        engine.cpp
        graphics.cpp
)

target_link_libraries(engine_sources
    PRIVATE
        Engine::Headers
        Engine::PrivateCompileOptions
        Modules::Backend
)

set_target_properties(engine_sources PROPERTIES
        CXX_CPPCHECK $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CPPCHECK>
        CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CLANG_TIDY>
)

add_library(Engine::Sources ALIAS engine_sources)
