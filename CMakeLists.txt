cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" FALSE)
option(ENABLE_TESTING "Enable the building of the test" ON)
option(ENABLE_ASAN "Enable address sanitizer" OFF)
option(ENABLE_CLANG_TIDY "Enable testing with clang-tidy" OFF)
option(ENABLE_CPPCHECK "Enable testing with cppcheck" OFF)
option(BUILD_EXAMPLES "Build engine usage examples" ON)

option(ENGINE_USE_SDL_BACKEND "Use sdl as engine backend" ON)

# set the project name
project(Engine LANGUAGES CXX VERSION 0.0.1)

# Misc settings
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set gloabl cpp standard
set(CMAKE_CXX_EXTENSIONS OFF)

# Add module paths
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Compilation flags
include(cmake/compile_options)

# Add sources
add_subdirectory(include)
add_subdirectory(src)

# Add engine backend
add_subdirectory(modules/engine_backend)

# Link all together

add_library(engine)

target_link_libraries(engine 
    PUBLIC 
        Engine::Headers
    PRIVATE 
        Engine::CompileOptions
        Engine::Sources
        Engine::Backend
)

set_target_properties(engine PROPERTIES 
    CXX_CPPCHECK $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CPPCHECK>
    CXX_CLANG_TIDY $<TARGET_PROPERTY:Engine::CompileOptions,CXX_CLANG_TIDY>
)

add_library(Engine ALIAS engine)

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

# Status
message("#########################################")
message("\t \t Summary")
message("#########################################")
message("Build type:         \t ${CMAKE_BUILD_TYPE}")
message("Install prefix:     \t ${CMAKE_INSTALL_PREFIX}")
message("Compiler:           \t ${CMAKE_CXX_COMPILER_ID}")
message("Shared libs:        \t ${BUILD_SHARED_LIBS}")
message("Testing enabled:    \t ${ENABLE_TESTING}")
message("Sanizizers:         \t ${ENABLE_ASAN}")
message("Clang-tidy:         \t ${ENABLE_CLANG_TIDY} ${CLANGTIDY}")
message("Cppcheck:           \t ${ENABLE_CPPCHECK} ${CPPCHECK}")
message("Building doc:       \t ${BUILD_DOC}")
message("Building examples:  \t ${BUILD_EXAMPLES}")
message("------------------------------------------")
message("Version:            \t ${PROJECT_VERSION}")
message("########################################")
