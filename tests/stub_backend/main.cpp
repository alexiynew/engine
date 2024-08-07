#include <iostream>

#include <engine_backend_factory.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(InitBackend, StubBackend)
{
    auto backend = game::modules::engine_backend::CreateBackend();
    backend->Init();
    backend->Quit();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
