#pragma once
#include <Hook/Hook.hpp>
#include <Utils/Structs.hpp>
#include <src/Features/Events/FovEvent.hpp>

class GammaHook : public Hook {
private:
    static float getGammaCallback(uintptr_t* a1);
    
public:
    GammaHook() : Hook() {
        mName = "Option::GetGamma";
    }
    static std::unique_ptr<Detour> mDetour;

    void init() override;

};

