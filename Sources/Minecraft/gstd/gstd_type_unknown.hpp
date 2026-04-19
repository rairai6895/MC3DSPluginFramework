#pragma once

namespace MC3DSPluginFramework::gstd
{
    template <size_t size = 1>
    class type_unknown
    {
        USE_GAME_ALLOCATOR
    public:
        type_unknown() = default;

    private:
        std::byte mField[size ? size : 1];
    };

    template <size_t size>
    using padding = type_unknown<size>;

}    // namespace MC3DSPluginFramework::gstd