#pragma once
#include <Hook/Hook.hpp>
#include <Utils/Structs.hpp>
#include <src/Features/Events/FovEvent.hpp>

class FovHook : public Hook {
public:
    FovHook() : Hook() {
        mName = "LevelRendererPlayer::getFov";
    }
    static std::unique_ptr<Detour> mDetour;
    static float getFovCallback(void* a1, float f, void* a3, void* a4);

    void init() override;

};

