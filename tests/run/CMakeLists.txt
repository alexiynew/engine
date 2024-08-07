cmake_path(GET CMAKE_CURRENT_LIST_DIR STEM LAST_ONLY DIR_NAME)
set(TEST_NAME ${DIR_NAME}_test)

add_executable(${TEST_NAME} main.cpp)

target_link_libraries(${TEST_NAME} PRIVATE 
    Engine
    Engine::CompileOptions
    Libs::GTest 
    Libs::GMock
)
