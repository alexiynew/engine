#include "stub_backend.hpp"

#include <iostream>

namespace engine::modules::engine_backend
{
    StubBackend::StubBackend()
    {
        std::cout << "StubBackend::StubBackend" << std::endl;
    }

    StubBackend::~StubBackend()
    {
        std::cout << "StubBackend::~StubBackend" << std::endl;
    }

    bool StubBackend::Init()
    {
        std::cout << "StubBackend::Init" << std::endl;
        return true;
    }

    void StubBackend::Quit()
    {
        std::cout << "StubBackend::Quit" << std::endl;
    }

} // namespace engine::modules::engine_backend
