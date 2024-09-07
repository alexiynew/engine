#include <iostream>

#include <engine/game.hpp>
#include <engine_backend/engine_backend.hpp>

namespace game
{
    Game::Game()
    {
        std::cout << "Game::Game" << std::endl;
    }

    Game::~Game()
    {
        std::cout << "Game::~Game" << std::endl;
    }

} // namespace game
