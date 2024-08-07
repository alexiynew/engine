#include "sdl_backend.hpp"

#include <iostream>

namespace game::modules::engine_backend
{
    SdlBackend::SdlBackend()
    {
        std::cout << "SdlBackend::SdlBackend" << std::endl;
    }

    SdlBackend::~SdlBackend()
    {
        std::cout << "SdlBackend::~SdlBackend" << std::endl;
    }

    bool SdlBackend::Init()
    {
        std::cout << "SdlBackend::Init" << std::endl;
        return true;
    }

    void SdlBackend::Quit()
    {
        std::cout << "SdlBackend::Quit" << std::endl;
    }

} // namespace game::modules::engine_backend
