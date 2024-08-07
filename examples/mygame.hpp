#include <engine/game.hpp>

class MyGame : public game::Game
{
public:
    MyGame();
    ~MyGame() override;

private:
    virtual void OnLoad() override;
    virtual void OnUpdate() override;
    virtual void OnDraw() override;
    virtual void OnQuit() override;
};
