include(FetchContent)

FetchContent_Declare(
    sdllib
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        main
)

set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)

set(SDL_DISABLE_INSTALL ON CACHE BOOL "" FORCE)
set(SDL_DISABLE_UNINSTALL ON CACHE BOOL "" FORCE)

set(SDL_CUSTOM_GCC_OPTIONS 
    -Wno-deprecated-declarations
)

FetchContent_MakeAvailable(sdllib)

target_compile_options(SDL3-static
    PRIVATE 
        $<$<COMPILE_LANG_AND_ID:C,${GCC_LIKE_COMPILER_ID}>:${SDL_CUSTOM_GCC_OPTIONS}>
)

set_target_properties(SDL3-static SDL_uclibc PROPERTIES FOLDER "libs/sdl")

# Disable clang analysis because it doesn't work in clang for Windows
target_compile_definitions(SDL3-static PUBLIC SDL_DISABLE_ANALYZE_MACROS)

# Define lids to link
add_library(Libs::SDL INTERFACE IMPORTED)
target_link_libraries(Libs::SDL INTERFACE SDL3-static)
target_include_directories(Libs::SDL INTERFACE ${sdllib_SOURCE_DIR}/include)
