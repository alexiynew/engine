#pragma once

namespace game::modules::engine_backend
{
    class Backend
    {
    public:
        Backend();

        virtual ~Backend();

        Backend(const Backend&) = delete;
        Backend(Backend&&);

        Backend& operator=(const Backend&) = delete;
        Backend& operator=(Backend&&);

        virtual bool Init() = 0;
        virtual void Quit() = 0;
    };

} // namespace game::modules::engine_backend
