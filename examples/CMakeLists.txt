add_executable(example)

target_sources(example 
    PRIVATE
        mygame.hpp
        mygame.cpp
)

target_link_libraries(example 
    PRIVATE 
        Engine
        Engine::EntryPoint # Need to link directly for compiler to see entry point
)

target_compile_features(example PRIVATE cxx_std_23)

set_target_properties(example PROPERTIES 
    FOLDER "examples"
    WIN32_EXECUTABLE ON
)
