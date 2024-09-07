#include <backend/backend.hpp>
#include <backend/backend_events_handler.hpp>

namespace engine::modules::engine_backend
{
    Backend::Backend() = default;

    Backend::~Backend() = default;

    Backend::Backend(Backend&&) noexcept = default;

    Backend& Backend::operator=(Backend&&) noexcept = default;

    void Backend::Quit()
    {
        m_should_quit = true;
    }

    bool Backend::ShouldQuit() const
    {
        return m_should_quit;
    }

} // namespace engine::modules::engine_backend
