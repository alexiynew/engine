add_executable(example)

target_sources(example 
    PRIVATE
        mygame.hpp
        mygame.cpp
        main.cpp
)

target_link_libraries(example 
    PRIVATE 
        Engine::CompileOptions
        Engine
)

set_target_properties(example PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CLANG_TIDY>
)