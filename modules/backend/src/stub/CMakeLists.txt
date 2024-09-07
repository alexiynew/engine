add_library(stub_backend STATIC "")

target_sources(stub_backend 
    PRIVATE
        stub_backend.hpp
        stub_backend.cpp
)

target_link_libraries(stub_backend 
    PRIVATE 
        Engine::PrivateCompileOptions
)

set_target_properties(stub_backend PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::PrivateCompileOptions,CXX_CLANG_TIDY>
)

target_include_directories(stub_backend PRIVATE ..)
