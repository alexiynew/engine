# Backend headers lib
add_library(engine_backend_headers INTERFACE)

target_sources(engine_backend_headers 
    INTERFACE
        engine_backend.hpp
        engine_backend_factory.hpp
)

target_include_directories(engine_backend_headers INTERFACE .)

add_library(Engine::BackendHeaders ALIAS engine_backend_headers)

# Backend lib
add_library(engine_backend INTERFACE)

if(${ENGINE_USE_SDL_BACKEND})
    add_subdirectory(sdl)
    target_link_libraries(engine_backend INTERFACE sdl_backend)
else()
    add_subdirectory(stub)
    target_link_libraries(engine_backend INTERFACE stub_backend)
endif()

add_library(Engine::Backend ALIAS engine_backend)
