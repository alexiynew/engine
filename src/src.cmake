target_sources(engine 
    PRIVATE 
        src/game.cpp
        src/graphics.cpp
)

target_include_directories(engine PRIVATE modules)
