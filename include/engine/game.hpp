#pragma once

#include <memory>

namespace game
{
    namespace modules::engine_backend
    {
        class Backend;
    }

    class Game
    {
    public:
        Game();
        virtual ~Game();

        virtual void OnInit()   = 0;
        virtual void OnEvent()  = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDraw()   = 0;
        virtual void OnQuit()   = 0;

    private:
        std::unique_ptr<modules::engine_backend::Backend> m_backend;
    };

    std::unique_ptr<Game> CreateGame();

} // namespace game
