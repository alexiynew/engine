#pragma once

#include <engine_backend.hpp>

namespace game::modules::engine_backend
{
    class SdlBackend : public Backend
    {
    public:
        SdlBackend();
        ~SdlBackend() override;

        SdlBackend(SdlBackend&&)            = default;
        SdlBackend& operator=(SdlBackend&&) = default;

        bool Init() override;
        void Quit() override;
    };

} // namespace game::modules::engine_backend
