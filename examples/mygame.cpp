#include "mygame.hpp"

#include <iostream>

MyGame::MyGame()
{
    std::cout << "MyGame::MyGame()" << std::endl;
}

MyGame::~MyGame()
{
    std::cout << "MyGame::~MyGame()" << std::endl;
}

void MyGame::OnLoad()
{
    std::cout << "MyGame::OnLoad()" << std::endl;
}

void MyGame::OnUpdate()
{
    std::cout << "MyGame::OnUpdate()" << std::endl;
}

void MyGame::OnDraw()
{
    std::cout << "MyGame::Draw()" << std::endl;

    Quit();
}

void MyGame::OnQuit()
{
    std::cout << "MyGame::OnQuit()" << std::endl;
}
