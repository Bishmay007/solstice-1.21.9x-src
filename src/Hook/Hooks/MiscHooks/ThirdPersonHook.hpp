#pragma once
#include <Hook/Hook.hpp>
#include <Utils/Structs.hpp>
#include <src/Features/Events/FovEvent.hpp>

class ThirdPersonHook : public Hook {
private:
    static unsigned int getThirdPersonCallback(__int64 a1);
    
public:
    ThirdPersonHook() : Hook() {
        mName = "Option::ThirdPerson";
    }
    static std::unique_ptr<Detour> mDetour;

    void init() override;

};

