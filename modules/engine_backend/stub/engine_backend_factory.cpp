#include <engine_backend_factory.hpp>
#include <stub/stub_backend.hpp>

namespace game::modules::engine_backend
{
    std::unique_ptr<Backend> CreateBackend()
    {
        return std::make_unique<StubBackend>();
    }

} // namespace game::modules::engine_backend
