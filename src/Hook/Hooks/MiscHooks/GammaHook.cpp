

#include "GammaHook.hpp"

#include <Features/Modules/Visual/FullBright.hpp>

std::unique_ptr<Detour> GammaHook::mDetour = nullptr;


float GammaHook::getGammaCallback(uintptr_t* a1) {
    auto FullB = gFeatureManager->mModuleManager->getModule<FullBright>();
    if (FullB->mEnabled) {
        return FullB->mCurrentGamma;
    }
    else return 1.f;

}
void GammaHook::init()
{
    mDetour = std::make_unique<Detour>("Option::GetGamma", reinterpret_cast<void*>(SigManager::GammaSig), &getGammaCallback);
}
