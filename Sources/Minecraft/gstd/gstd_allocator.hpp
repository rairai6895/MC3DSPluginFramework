#pragma once

namespace MC3DSPluginFramework::gstd
{
    template <typename _Tp>
    class allocator
    {
    public:
        using value_type = _Tp;

        _Tp *allocate(size_t n) { return reinterpret_cast<_Tp *>(gstd::malloc(sizeof(_Tp) * n)); }
        void deallocate(_Tp *ptr, size_t n) { gstd::free(ptr); }
        bool operator==(const allocator &) const { return true; }
        bool operator!=(const allocator &) const { return false; }
    };
}    // namespace MC3DSPluginFramework::gstd