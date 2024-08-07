#pragma once

namespace game::modules::engine_backend
{
    class Backend
    {
    public:
        Backend() = default;

        virtual ~Backend() = default;

        Backend(const Backend&) = delete;
        Backend(Backend&&)      = default;

        Backend& operator=(const Backend&) = delete;
        Backend& operator=(Backend&&)      = default;

        virtual bool Init() = 0;
        virtual void Quit() = 0;
    };

} // namespace game::modules::engine_backend
