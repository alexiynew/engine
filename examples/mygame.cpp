#include "mygame.hpp"

#include <iostream>

namespace engine
{
    std::unique_ptr<Engine> CreateGame()
    {
        return std::make_unique<MyGame>();
    }
} // namespace engine

MyGame::MyGame()
{
    std::cout << "MyGame::MyGame()" << std::endl;
}

MyGame::~MyGame()
{
    std::cout << "MyGame::~MyGame()" << std::endl;
}

void MyGame::OnInit()
{
    std::cout << "MyGame::OnLoad()" << std::endl;
}

void MyGame::OnEvent()
{
    std::cout << "MyGame::OnEvent()" << std::endl;
}

void MyGame::OnUpdate()
{
    std::cout << "MyGame::OnUpdate()" << std::endl;
}

void MyGame::OnDraw()
{
    std::cout << "MyGame::Draw()" << std::endl;
}

void MyGame::OnQuit()
{
    std::cout << "MyGame::OnQuit()" << std::endl;
}
