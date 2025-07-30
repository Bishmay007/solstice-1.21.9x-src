

#include "FovHook.hpp"

#include <Features/Events/FovEvent.hpp>

std::unique_ptr<Detour> FovHook::mDetour = nullptr;


float FovHook::getFovCallback(void* a1, float f, void* a3, void* a4) {

    auto oFunc = mDetour->getOriginal<&getFovCallback>();

	float lawl = oFunc(a1, f, a3, a4);

    auto event = nes::make_holder<FovEvent>(lawl);
    gFeatureManager->mDispatcher->trigger(event);
	return event->getFov();
}
void FovHook::init()
{
    mDetour = std::make_unique<Detour>("LevelRendererPlayer::getFov", reinterpret_cast<void*>(SigManager::FovHk), &getFovCallback);
}
