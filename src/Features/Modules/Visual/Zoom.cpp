//
// Created by alteik on 15/10/2024.
//

#include "Zoom.hpp"
#include <SDK/Minecraft/Actor/Actor.hpp>
#include <SDK/Minecraft/ClientInstance.hpp>
#include <SDK/Minecraft/Options.hpp>
#include <src/Features/Events/FovEvent.hpp>

void Zoom::onEnable()
{

    gFeatureManager->mDispatcher->listen<MouseEvent, &Zoom::onMouseEvent>(this);
    gFeatureManager->mDispatcher->listen<RenderEvent, &Zoom::onRenderEvent>(this);
    gFeatureManager->mDispatcher->listen<FovEvent, &Zoom::onFov>(this);
    gFeatureManager->mDispatcher->listen<BaseTickEvent, &Zoom::onBaseTickEvent>(this);

}

void Zoom::onDisable()
{
    gFeatureManager->mDispatcher->deafen<MouseEvent, &Zoom::onMouseEvent>(this);
    gFeatureManager->mDispatcher->deafen<RenderEvent, &Zoom::onRenderEvent>(this);

	gFeatureManager->mDispatcher->deafen<BaseTickEvent, &Zoom::onBaseTickEvent>(this);

    gFeatureManager->mDispatcher->deafen<FovEvent, &Zoom::onFov>(this);
}
void Zoom::onBaseTickEvent(BaseTickEvent& event)
{
	//ChatUtils::displayClientMessage("Zoom: " + std::to_string(mZoomValue.mValue) + " | Smooth: " + std::to_string(mSmooth.mValue) + " | Scroll: " + std::to_string(mScroll.mValue) + " | Increment: " + std::to_string(mScrollIncrement.mValue)+ " | raw: " + std::to_string(fov)+" | ch: " + std::to_string(fv));
}

void Zoom::onMouseEvent(MouseEvent& event)
{
    if (ClientInstance::get()->getMouseGrabbed()) return;
    if (!mScroll.mValue) return;

    if (event.mActionButtonId == 4)
    {
        if(event.mButtonData == 0x78 || event.mButtonData == 0x7F)
        {
            mZoomValue.mValue -= mScrollIncrement.mValue;
            event.cancel();
            return;
        }
        else if (event.mButtonData == 0x88 || event.mButtonData == 0x80 || event.mButtonData == -0x78)
        {
            mZoomValue.mValue += mScrollIncrement.mValue;
            event.cancel();
            return;

        }

    }


    if (mZoomValue.mValue < 10.f) mZoomValue.mValue = 10.f;
    if (mCurrentValue < 10.f) mCurrentValue = 10.f;
}


void Zoom::onFov(FovEvent& event) {
    if (!this->mEnabled) 
        return ;
    mCurrentZoom = event.getFov();
    event.setFov(mSetZoom);

}
void Zoom::onRenderEvent(RenderEvent& event)
{
    auto player = ClientInstance::get()->getLocalPlayer();
    if (!player) return;
    if (mCurrentValue > 170) {
        mCurrentValue = MathUtils::lerp(mCurrentValue, 170, ImGui::GetIO().DeltaTime * 5.f);
        mSetZoom = mCurrentValue;
        return;
    }
    else if (mCurrentValue < 0) {
        mCurrentValue = MathUtils::lerp(mCurrentValue, 0, ImGui::GetIO().DeltaTime * 5.f);
		mSetZoom = mCurrentValue;
        return;
    }
   
   if (mSmooth.mValue)
    {
        mCurrentValue = MathUtils::lerp(mCurrentValue, mZoomValue.mValue, ImGui::GetIO().DeltaTime * 10.f);
        mSetZoom = mCurrentValue;
    }
    else
    {
       mSetZoom = mCurrentValue;
    }
    
}

