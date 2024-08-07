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

        void Run();
        void Quit();

    protected:
        virtual void OnLoad()   = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDraw()   = 0;
        virtual void OnQuit()   = 0;

    private:
        bool m_running = false;
        std::unique_ptr<modules::engine_backend::Backend> m_backend;
    };

} // namespace game
