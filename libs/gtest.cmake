include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_library(Libs::GTest INTERFACE IMPORTED)
target_link_libraries(Libs::GTest INTERFACE gtest_main)
target_include_directories(Libs::GTest INTERFACE ${googletest_SOURCE_DIR}/googletest/include)
target_compile_options(gtest PRIVATE -Wno-undef)
target_compile_options(gtest_main PRIVATE -Wno-undef)

add_library(Libs::GMock INTERFACE IMPORTED)
target_link_libraries(Libs::GMock INTERFACE gmock_main)
target_include_directories(Libs::GMock INTERFACE ${googletest_SOURCE_DIR}/googletest/include)
target_compile_options(gmock PRIVATE -Wno-undef)
target_compile_options(gmock_main PRIVATE -Wno-undef)
