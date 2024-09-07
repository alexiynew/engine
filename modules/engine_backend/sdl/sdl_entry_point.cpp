#include <iostream>

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_main.h>

namespace
{
    struct AppState
    {
        /// The window we'll open to show our rendering inside.
        SDL_Window* window{nullptr};
        /// Count of the number of times the main loop has been run.
        long long iterations{0};

        //        std::unique_ptr<Game::Game> game;
        //        std::unique_ptr<Backend::Backend> backend;
    };
} // namespace

extern "C"
{
    SDL_AppResult SDL_AppInit(void** appstate, int /*argc*/, char** /*argv*/)
    {
        std::cerr << "SDL_AppInit" << std::endl;

        // Create an object that will be passed back to each callback:
        *appstate       = new AppState;
        AppState& state = *static_cast<AppState*>(*appstate);

        const int result = SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        if (result < 0) {
            std::cerr << "SDL_InitSubSystem failed with code " << result << std::endl;
            goto error_exit;
        }

        state.window = SDL_CreateWindow("SDL3 Window", 960, 540, 0 /* | SDL_WINDOW_VULKAN*/);
        if (state.window == NULL) {
            std::cerr << "SDL_CreateWindow failed" << std::endl;
            goto error_exit;
        }

        // try {
        // state.backend = std::make_unique<Backend::Backend>();
        // state.game    = Game::CreateGame(*state.backend);
        //} catch (...) {
        // return SDL_APP_FAILURE;
        //}

        return SDL_APP_CONTINUE;

    error_exit:
        std::cerr << "Last SDL error: " << SDL_GetError() << std::endl;
        return SDL_APP_FAILURE;
    }

    SDL_AppResult SDL_AppIterate(void* appstate)
    {
        AppState& state = *static_cast<AppState*>(appstate);

        // if (state.backend->ShouldQuit()) {
        //     return SDL_APP_SUCCESS;
        // }

        // state.game->OnUpdate();
        // state.game->OnDraw();

        ++state.iterations;

        return SDL_APP_CONTINUE;
    }

    SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
    {
        (void)appstate;
        // AppState& state = *static_cast<AppState*>(appstate);

        if (event->type == SDL_EVENT_KEY_DOWN) {
            const SDL_KeyboardEvent& key_event = event->key;
            if (key_event.key == SDLK_ESCAPE) {
                std::cerr << "SDL_EVENT_KEY_DOWN ESCAPE" << std::endl;

                // state.game->OnEvent();

                return SDL_APP_SUCCESS;
            }
        }

        if (event->type == SDL_EVENT_QUIT) {
            std::cerr << "SDL_EVENT_QUIT" << std::endl;
            return SDL_APP_SUCCESS;
        }
        return SDL_APP_CONTINUE;
    }

    void SDL_AppQuit(void* appstate)
    {
        AppState* state = static_cast<AppState*>(appstate);
        std::cerr << "SDL_AppQuit after " << state->iterations << " iterations of the main loop." << std::endl;
        delete state;
        return;
    }
}
