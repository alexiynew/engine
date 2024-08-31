# Backend lib
add_library(engine_backend STATIC)

target_sources(engine_backend
    PUBLIC
        engine_backend.hpp
    PRIVATE
        engine_backend.cpp
)

target_link_libraries(engine_backend 
    PRIVATE 
        Engine::PrivateCompileOptions
)

set_target_properties(engine_backend PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CLANG_TIDY>
)

target_include_directories(engine_backend PRIVATE .)

add_library(engine_entry_point OBJECT)

# Backend implementation lib
if(${ENGINE_USE_SDL_BACKEND})
    include(sdl/sdl_backend.cmake)
else()
    include(stub/stub_backend)
endif()

add_library(Engine::Backend ALIAS engine_backend)
add_library(Engine::EntryPoint ALIAS engine_entry_point)
