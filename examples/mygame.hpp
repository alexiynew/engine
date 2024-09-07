#include <engine/engine.hpp>

class MyGame : public engine::Engine
{
public:
    MyGame();
    ~MyGame() override;

private:
    virtual void OnInit() override;
    virtual void OnEvent() override;
    virtual void OnUpdate() override;
    virtual void OnDraw() override;
    virtual void OnQuit() override;
};
