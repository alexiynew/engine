#include <chrono>
#include <iostream>
#include <stdexcept>
#include <thread>

#include <engine/game.hpp>
#include <engine_backend_factory.hpp>

namespace game
{
    Game::Game()
        : m_backend(modules::engine_backend::CreateBackend())
    {
        std::cout << "Game::Game" << std::endl;
    }

    Game::~Game()
    {
        std::cout << "Game::~Game" << std::endl;
    }

    void Game::Run()
    {
        std::cout << "Game::Run" << std::endl;

        if (!m_backend->Init()) {
            throw std::runtime_error("Can't init backend");
        }

        OnLoad();
        m_running = true;

        while (m_running) {
            OnUpdate();
            OnDraw();

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        m_backend->Quit();
    }

    void Game::Quit()
    {
        std::cout << "Game::Quit" << std::endl;

        OnQuit();
        m_running = false;
    }

} // namespace game
