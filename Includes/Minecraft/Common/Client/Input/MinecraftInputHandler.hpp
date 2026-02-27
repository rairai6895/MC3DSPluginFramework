#pragma once

namespace MC3DSPluginFramework
{
    class PlayerController;

    // "C:\\Projects\\MC\\3DSPostLaunchPatch85\\handheld\\src\\common\\client\\input\\MinecraftInputHandler.cpp"
    class MinecraftInputHandler
    {
    public:
        MinecraftInputHandler(PlayerController *parent);

    public:
        virtual ~MinecraftInputHandler();

    private:
        struct UnknownClass1
        {
            // FUN_0x23AAA0

            float mUnk1 = 0;
            float mUnk2 = 0;
            float mUnk3 = 0;
            float mUnk4 = 0;
        };

        // 0x9C3900

        PlayerController *mParent;
        UnknownClass1 mUnk1[30];
    };
}    // namespace MC3DSPluginFramework