include(libs/gtest)

add_subdirectory(run)
add_subdirectory(stub_backend)
add_subdirectory(sdl_backend)

add_test(run run/run_test)
add_test(stub_backend stub_backend/stub_backend_test)
add_test(sdl_backend sdl_backend/sdl_backend_test)
