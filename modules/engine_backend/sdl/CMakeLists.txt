add_library(sdl_backend STATIC "")

target_sources(sdl_backend 
    PRIVATE
        engine_backend_factory.cpp
        sdl_backend.hpp
        sdl_backend.cpp
)

target_link_libraries(sdl_backend 
    PRIVATE 
        Engine::CompileOptions
        Engine::BackendHeaders
)

set_target_properties(sdl_backend PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CLANG_TIDY>
)
