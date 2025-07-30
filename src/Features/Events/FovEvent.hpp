#pragma once

#include "Event.hpp"

class FovEvent : public CancelableEvent {
private:
    float fov;
public:
    [[nodiscard]] float getFov() const {
        return this->fov;
    }

    void setFov(float e) {
        this->fov = e;
    }

    explicit FovEvent(float fov) {
		this->fov = fov;
    }
};