cmake_path(GET CMAKE_CURRENT_LIST_DIR STEM LAST_ONLY DIR_NAME)
set(TEST_NAME ${DIR_NAME}_test)

add_executable(${TEST_NAME} main.cpp)

if(NOT TARGET sdl_backend)
    add_subdirectory(${CMAKE_SOURCE_DIR}/modules/engine_backend/sdl ${CMAKE_CURRENT_BINARY_DIR}/sdl)
endif()

target_link_libraries(${TEST_NAME} PRIVATE 
    sdl_backend
)

target_link_libraries(${TEST_NAME} PRIVATE 
    Engine::CompileOptions
    Engine::Headers
    Engine::BackendHeaders
    Engine::Sources
    Libs::GTest 
    Libs::GMock
)
