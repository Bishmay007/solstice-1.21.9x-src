#pragma once

#include "Event.hpp"

class ThirdPersonEvent : public CancelableEvent {
private:
    unsigned int mCuurent;
public:
    [[nodiscard]] unsigned int getCurrent() const {
        return this->mCuurent;
    }

    void setCurrent(unsigned int e) {
        this->mCuurent = e;
    }

    explicit ThirdPersonEvent(unsigned int a1) {
		this->mCuurent = a1;
    }
};