# Backend lib
add_library(modules_backend STATIC)

target_sources(modules_backend
    PUBLIC
        include/backend/backend.hpp
        include/backend/backend_events_handler.hpp
        include/backend/key_event.hpp
    PRIVATE
        src/backend.cpp
)

target_link_libraries(modules_backend
    PRIVATE 
        Engine::PrivateCompileOptions
)

set_target_properties(modules_backend PROPERTIES
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CLANG_TIDY>
)

target_include_directories(modules_backend
    PUBLIC
        include 
    PRIVATE 
        src
)

# Entry point lib
add_library(engine_entry_point OBJECT)

target_link_libraries(engine_entry_point 
    PRIVATE 
        Engine::PrivateCompileOptions
)

set_target_properties(engine_entry_point PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CLANG_TIDY>
)

target_include_directories(engine_entry_point 
    PRIVATE 
        include 
        src
)

# Backend implementation lib
if(${ENGINE_USE_SDL_BACKEND})
    include(src/sdl/sdl_backend.cmake)
else()
    include(src/stub/stub_backend)
endif()

add_library(Modules::Backend ALIAS modules_backend)
add_library(Engine::EntryPoint ALIAS engine_entry_point)
