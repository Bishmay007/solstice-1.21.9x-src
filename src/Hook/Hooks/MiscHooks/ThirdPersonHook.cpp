

#include "ThirdPersonHook.hpp"

#include <Features/Events/ThirdPersonEvent.hpp>

std::unique_ptr<Detour> ThirdPersonHook::mDetour = nullptr;


unsigned int ThirdPersonHook::getThirdPersonCallback(__int64 a1) {  
    auto oFunc = mDetour->getOriginal<&getThirdPersonCallback>();  

	unsigned int lawl = oFunc(a1);
    auto holder = nes::make_holder<ThirdPersonEvent>(lawl);
    gFeatureManager->mDispatcher->trigger<ThirdPersonEvent>(holder);


	return holder->getCurrent();
}
void ThirdPersonHook::init()
{
    mDetour = std::make_unique<Detour>("Option::ThirdPerson", reinterpret_cast<void*>(SigManager::Fistpr), &getThirdPersonCallback);
}
