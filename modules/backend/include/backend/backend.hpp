#pragma once

#include <memory>

namespace engine::modules::engine_backend
{
    class BackendEventHandler;

    class Backend
    {
    public:
        Backend();

        virtual ~Backend();

        Backend(const Backend&) = delete;
        Backend(Backend&&) noexcept;

        Backend& operator=(const Backend&) = delete;
        Backend& operator=(Backend&&) noexcept;

        void Quit();
        bool ShouldQuit() const;

    private:
        bool m_should_quit = false;

        std::unique_ptr<BackendEventHandler> m_eventHandler;
    };

} // namespace engine::modules::engine_backend
