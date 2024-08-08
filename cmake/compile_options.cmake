
add_library(engine_compile_options INTERFACE)

set(GCC_LIKE_COMPILER $<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>)
set(MSVC_LIKE_COMPILER $<COMPILE_LANG_AND_ID:CXX,MSVC>)

set(GCC_OPTIONS 
    -Wall
    -Wextra
    -Wshadow
    -Wpedantic
    -Wconversion
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wsign-conversion
    -Wnull-dereference
    -Wdouble-promotion
    -Wformat=2
    -Wmisleading-indentation
    -Werror
)

set(MSVC_OPTIONS 
    -W4
    -WX
    -DNOMINMAX
    -DUNICODE
    -MT
)

target_compile_features(engine_compile_options INTERFACE cxx_std_23)

target_compile_options(engine_compile_options INTERFACE $<${GCC_LIKE_COMPILER}:${GCC_OPTIONS}>)
target_compile_options(engine_compile_options INTERFACE $<${MSVC_LIKE_COMPILER}:${MSVC_OPTIONS}>)

if(ENABLE_ASAN)
    target_compile_options(engine_compile_options INTERFACE -fsanitize=address)
    target_link_libraries(engine_compile_options INTERFACE -fsanitize=address)
endif()

if(ENABLE_CLANG_TIDY)
    find_program(CLANGTIDY clang-tidy)
    if(CLANGTIDY)
        set(CXX_CLANG_TIDY ${CLANGTIDY})
        set_target_properties(engine_compile_options PROPERTIES CXX_CLANG_TIDY "${CXX_CLANG_TIDY}")
    else()
        message(SEND_ERROR "clang-tidy requested but executable not found")
    endif()
endif()

if(ENABLE_CPPCHECK)
    find_program(CPPCHECK cppcheck)
    if(CPPCHECK)
        set(CXX_CPPCHECK
            ${CPPCHECK}
            --enable=all
            --suppressions-list=${CMAKE_CURRENT_SOURCE_DIR}/suppress.cppcheck
            --inconclusive)
        set_target_properties(engine_compile_options PROPERTIES CXX_CPPCHECK "${CXX_CPPCHECK}")
    else()
        message(SEND_ERROR "cppcheck requested but executable not found")
    endif()
endif()

add_library(Engine::CompileOptions ALIAS engine_compile_options)
