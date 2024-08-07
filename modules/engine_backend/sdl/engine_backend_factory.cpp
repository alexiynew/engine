#include <engine_backend_factory.hpp>
#include <sdl/sdl_backend.hpp>

namespace game::modules::engine_backend
{
    std::unique_ptr<Backend> CreateBackend()
    {
        return std::make_unique<SdlBackend>();
    }

} // namespace game::modules::engine_backend
