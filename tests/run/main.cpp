#include <iostream>

#include <engine/game.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class GameMock : public game::Game
{
public:
    MOCK_METHOD(void, OnInit, (), (override));
    MOCK_METHOD(void, OnEvent, (), (override));
    MOCK_METHOD(void, OnUpdate, (), (override));
    MOCK_METHOD(void, OnDraw, (), (override));
    MOCK_METHOD(void, OnQuit, (), (override));
};

TEST(RunTest, DefaultLoop)
{
    //    using testing::Expectation;
    //    using testing::Invoke;
    //
    //    GameMock gameMock;
    //
    //    ON_CALL(gameMock, OnDraw).WillByDefault(Invoke(&gameMock, &GameMock::Quit));
    //
    //    Expectation loadCall   = EXPECT_CALL(gameMock, OnLoad).Times(1);
    //    Expectation updateCall = EXPECT_CALL(gameMock, OnUpdate).Times(1).After(loadCall);
    //    Expectation drawCall   = EXPECT_CALL(gameMock, OnDraw).Times(1).After(loadCall, updateCall);
    //    EXPECT_CALL(gameMock, OnQuit).Times(1).After(loadCall, updateCall, drawCall);
    //
    //    gameMock.Run();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);

    return RUN_ALL_TESTS();
}
