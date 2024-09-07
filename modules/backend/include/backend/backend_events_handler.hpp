#pragma once

#include <backend/key_event.hpp>

namespace engine::modules::engine_backend
{
    class BackendEventHandler
    {
    public:
        virtual ~BackendEventHandler() = default;

        virtual bool OnInit()                          = 0;
        virtual void OnKeyEvent(const KeyEvent& event) = 0;
        virtual void OnIterate()                       = 0;
        virtual void OnQuit()                          = 0;
    };
} // namespace engine::modules::engine_backend
