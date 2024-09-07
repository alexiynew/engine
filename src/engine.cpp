#include <iostream>

#include <backend/backend.hpp>
#include <engine/engine.hpp>

namespace engine
{
    Engine::Engine()
    {
        std::cout << "Game::Game" << std::endl;
    }

    Engine::~Engine()
    {
        std::cout << "Game::~Game" << std::endl;
    }

} // namespace engine
