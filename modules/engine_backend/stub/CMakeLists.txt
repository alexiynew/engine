add_library(stub_backend STATIC "")

target_sources(stub_backend 
    PRIVATE
        engine_backend_factory.cpp
        stub_backend.hpp
        stub_backend.cpp
)

target_link_libraries(stub_backend 
    PRIVATE 
        Engine::CompileOptions
        Engine::BackendHeaders
)

set_target_properties(stub_backend PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CLANG_TIDY>
)
