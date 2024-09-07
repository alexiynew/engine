#include "sdl_backend.hpp"

#include <iostream>
#include <format>

namespace engine::modules::engine_backend
{
    SdlBackend::SdlBackend()
    {
        std::cout << "SdlBackend::SdlBackend" << std::endl;
    }

    SdlBackend::~SdlBackend()
    {
        std::cout << "SdlBackend::~SdlBackend" << std::endl;
    }

    bool SdlBackend::OnInit()
    {
        std::cout << "SdlBackend::Init" << std::endl;

        const int result = SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        if (result < 0) {
            std::cout << "SDL_InitSubSystem failed with code " << result << std::endl;
            return false;
        }

        m_window = SDL_CreateWindow("SDL3 Window", 960, 540, 0 /* | SDL_WINDOW_VULKAN*/);
        if (m_window == nullptr) {
            std::cout << "SDL_CreateWindow failed" << std::endl;
            return false;
        }

        return true;
    }

    void SdlBackend::OnEvent(const SDL_Event* event)
    {
        m_event_count++;

        if (event->type == SDL_EVENT_KEY_DOWN) {
            const SDL_KeyboardEvent& key_event = event->key;
            if (key_event.key == SDLK_ESCAPE) {
                Quit();
            }
        }

        if (event->type == SDL_EVENT_QUIT) {
            Quit();
        }
    }

    void SdlBackend::OnIterate()
    {
        m_iterate_count++;
    }

    void SdlBackend::OnQuit()
    {
        std::cout << std::format("{}\n\t{:15}{}\n\t{:15}{}",
                                 "SdlBackend::Quit",
                                 "events",
                                 m_event_count,
                                 "iterates",
                                 m_iterate_count)
                  << std::endl;
    }

} // namespace engine::modules::engine_backend
