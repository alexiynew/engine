#include "engine_backend.hpp"

namespace game::modules::engine_backend
{
    Backend::Backend() = default;

    Backend::~Backend() = default;

    Backend::Backend(Backend&&) = default;

    Backend& Backend::operator=(Backend&&) = default;

} // namespace game::modules::engine_backend
