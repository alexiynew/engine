#pragma once

#include <memory>

#include <SDL3/SDL.h>
#include <backend/backend.hpp>

namespace engine::modules::engine_backend
{
    class SdlBackend : public Backend
    {
    public:
        SdlBackend();
        ~SdlBackend() override;

        SdlBackend(SdlBackend&&)            = default;
        SdlBackend& operator=(SdlBackend&&) = default;

        bool OnInit();
        void OnEvent(const SDL_Event* event);
        void OnIterate();
        void OnQuit();

    private:
        std::size_t m_event_count   = 0;
        std::size_t m_iterate_count = 0;

        SDL_Window* m_window = nullptr;
    };

} // namespace engine::modules::engine_backend
