cmake_path(GET CMAKE_CURRENT_LIST_DIR STEM LAST_ONLY DIR_NAME)
set(TEST_NAME ${DIR_NAME}_test)

add_executable(${TEST_NAME} main.cpp)

if(NOT TARGET stub_backend)
    add_subdirectory(${CMAKE_SOURCE_DIR}/modules/engine_backend/stub ${CMAKE_CURRENT_BINARY_DIR}/stub)
endif()

target_link_libraries(${TEST_NAME} 
    PRIVATE 
        stub_backend
        Engine::CompileOptions
        Engine::BackendHeaders
        Engine::Sources
        Libs::GTest 
        Libs::GMock
)

set_target_properties(${TEST_NAME} PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CLANG_TIDY>
)
