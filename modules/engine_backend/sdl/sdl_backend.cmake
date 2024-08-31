
# SDL sources
target_sources(engine_backend 
    PRIVATE
        sdl/sdl_backend.hpp
        sdl/sdl_backend.cpp
)

# SDL lib
include(libs/sdl)
target_link_libraries(engine_backend 
    PRIVATE 
        Libs::SDL
)

# Entry point
target_sources(engine_entry_point 
    PRIVATE 
        sdl/sdl_entry_point.cpp
)

target_link_libraries(engine_entry_point 
    PRIVATE 
        Libs::SDL
)
