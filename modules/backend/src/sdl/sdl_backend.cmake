
# SDL sources
target_sources(modules_backend
    PRIVATE
        src/sdl/sdl_backend.hpp
        src/sdl/sdl_backend.cpp
)

# SDL lib
include(libs/sdl)
target_link_libraries(modules_backend
    PRIVATE 
        Libs::SDL
)

# Entry point
target_sources(engine_entry_point 
    PRIVATE 
        src/sdl/sdl_entry_point.cpp
)

target_link_libraries(engine_entry_point 
    PRIVATE 
        Libs::SDL
)
