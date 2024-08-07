add_executable(example)

target_sources(example PRIVATE
    mygame.hpp
    mygame.cpp
    main.cpp
)

target_link_libraries(example PRIVATE Engine::CompileOptions)
target_link_libraries(example PRIVATE Engine)
