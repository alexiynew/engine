add_library(engine_backend_headers INTERFACE)

target_sources(engine_backend_headers INTERFACE
    engine_backend.hpp
    engine_backend_factory.hpp
)
target_include_directories(engine_backend_headers INTERFACE .)

add_library(Engine::BackendHeaders ALIAS engine_backend_headers)

add_library(engine_backend STATIC "")

target_link_libraries(engine_backend PRIVATE Engine::CompileOptions)
target_link_libraries(engine_backend PRIVATE Engine::BackendHeaders)

if(${ENGINE_USE_SDL_BACKEND})
    add_subdirectory(sdl)
    target_link_libraries(engine_backend PRIVATE sdl_backend)
else()
    include(stub)
    target_link_libraries(engine_backend PRIVATE stub_backend)
endif()

add_library(Engine::Backend ALIAS engine_backend)
