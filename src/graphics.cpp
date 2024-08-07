#include <iostream>

#include <engine/graphics.hpp>

namespace game
{
    Graphics::Graphics()
    {
        std::cout << "Graphics::Graphics" << std::endl;
    }

    Graphics::~Graphics()
    {
        std::cout << "Graphics::~Graphics" << std::endl;
    }

} // namespace game
