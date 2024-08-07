#pragma once

#include <engine_backend.hpp>

namespace game::modules::engine_backend
{
    class StubBackend : public Backend
    {
    public:
        StubBackend();
        ~StubBackend() override;

        StubBackend(StubBackend&&)            = default;
        StubBackend& operator=(StubBackend&&) = default;

        bool Init() override;
        void Quit() override;
    };

} // namespace game::modules::engine_backend
