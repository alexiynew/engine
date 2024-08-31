set(GCC_LIKE_COMPILER_ID ARMClang,AppleClang,Clang,GNU,LCC)
set(MSVC_LIKE_COMPILER_ID MSVC)

set(GCC_LIKE_COMPILER $<COMPILE_LANG_AND_ID:CXX,${GCC_LIKE_COMPILER_ID}>)
set(MSVC_LIKE_COMPILER $<COMPILE_LANG_AND_ID:CXX,${MSVC_LIKE_COMPILER_ID}>)

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
    /W4
    /WX
    /DUNICODE
    /D_UNICODE
)

add_library(private_compile_options INTERFACE)

target_compile_features(private_compile_options INTERFACE cxx_std_23)

target_compile_options(private_compile_options 
    INTERFACE 
        $<${GCC_LIKE_COMPILER}:${GCC_OPTIONS}>
        $<${MSVC_LIKE_COMPILER}:${MSVC_OPTIONS}>
)

if(ENABLE_ASAN)
    target_compile_options(private_compile_options INTERFACE -fsanitize=address)
    target_link_libraries(private_compile_options INTERFACE -fsanitize=address)
endif()

if(ENABLE_CLANG_TIDY)
    find_program(CLANGTIDY clang-tidy)
    if(CLANGTIDY)
        set(CXX_CLANG_TIDY ${CLANGTIDY})
        set_target_properties(private_compile_options PROPERTIES CXX_CLANG_TIDY "${CXX_CLANG_TIDY}")
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
        set_target_properties(private_compile_options PROPERTIES CXX_CPPCHECK "${CXX_CPPCHECK}")
    else()
        message(SEND_ERROR "cppcheck requested but executable not found")
    endif()
endif()

add_library(Engine::PrivateCompileOptions ALIAS private_compile_options)
