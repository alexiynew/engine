#pragma once

#include <memory>

#include <engine_backend.hpp>

namespace game::modules::engine_backend
{
    std::unique_ptr<Backend> CreateBackend();
} // namespace game::modules::engine_backend
