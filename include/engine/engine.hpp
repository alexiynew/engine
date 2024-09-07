#pragma once

#include <memory>

namespace engine
{
    namespace modules::engine_backend
    {
        class Backend;
    }

    class Engine
    {
    public:
        Engine();
        virtual ~Engine();

        virtual void OnInit()   = 0;
        virtual void OnEvent()  = 0;
        virtual void OnUpdate() = 0;
        virtual void OnDraw()   = 0;
        virtual void OnQuit()   = 0;

    private:
        std::unique_ptr<modules::engine_backend::Backend> m_backend;
    };

    std::unique_ptr<Engine> CreateGame();

} // namespace engine
