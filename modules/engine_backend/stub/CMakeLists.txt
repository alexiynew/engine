add_library(stub_backend STATIC "")

target_link_libraries(stub_backend PRIVATE Engine::CompileOptions)
target_link_libraries(stub_backend PRIVATE Engine::BackendHeaders)

target_include_directories(stub_backend PRIVATE .)

target_sources(stub_backend PRIVATE
    engine_backend_factory.cpp
    stub_backend.hpp
    stub_backend.cpp
)
