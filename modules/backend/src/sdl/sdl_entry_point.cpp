#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <sdl/sdl_backend.hpp>

using namespace engine::modules::engine_backend;

namespace
{
    struct AppState
    {
        std::unique_ptr<SdlBackend> backend;
    };
} // namespace

extern "C"
{
    SDL_AppResult SDL_AppInit(void** appstate, int /*argc*/, char** /*argv*/)
    {
        try {
            // Create an object that will be passed back to each callback:
            *appstate       = new AppState;
            AppState& state = *static_cast<AppState*>(*appstate);

            state.backend = std::make_unique<SdlBackend>();
            if (!state.backend->OnInit()) {
                return SDL_APP_FAILURE;
            }
        } catch (...) {
            return SDL_APP_FAILURE;
        }

        return SDL_APP_CONTINUE;
    }

    SDL_AppResult SDL_AppIterate(void* appstate)
    {
        AppState& state = *static_cast<AppState*>(appstate);

        if (state.backend->ShouldQuit()) {
            return SDL_APP_SUCCESS;
        }

        state.backend->OnIterate();

        return SDL_APP_CONTINUE;
    }

    SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
    {
        AppState& state = *static_cast<AppState*>(appstate);
        state.backend->OnEvent(event);

        return SDL_APP_CONTINUE;
    }

    void SDL_AppQuit(void* appstate)
    {
        auto* state = static_cast<AppState*>(appstate);
        state->backend->OnQuit();
        delete state;
    }
}
