add_library(sdl_backend STATIC "")

target_link_libraries(sdl_backend PRIVATE Engine::CompileOptions)
target_link_libraries(sdl_backend PRIVATE Engine::BackendHeaders)

target_include_directories(sdl_backend PRIVATE .)

target_sources(sdl_backend PRIVATE
    engine_backend_factory.cpp
    sdl_backend.hpp
    sdl_backend.cpp
)
