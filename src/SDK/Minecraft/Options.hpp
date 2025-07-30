#pragma once  
//  
// Created by vastrakai on 7/8/2024.  
//  
#include <xmmintrin.h>
#include <vector>  
#include <Utils/MemUtils.hpp>  

class IntOption {  
public:  
    PAD(0x10);  
    int maximum;  
    PAD(0x4);  
    int value;  
    PAD(0x4);  
    int minimum;  
};  


static_assert(sizeof(IntOption) == 36, "IntOption size is incorrect!");  


class FloatOption {  
public:  
    float unk;
    float mMinimum;  
    float mMaximum;  
    float mValue;  
    float mDefaultValue;  
};  

class Options {  
public:  
   // CLASS_FIELD(IntOption*, mThirdPerson, 0x30);  
    CLASS_FIELD(void*, mViewBob, 0x120);  
  //  CLASS_FIELD(FloatOption*, mGfxFieldOfView, 0x68);
    CLASS_FIELD(float*, mGfxGamma, 0x160);  



    //FloatOption* mGfxGamma(); // its gamma
   // IntOption* mThirdPerson();

    int* mThirdPersons(); // its third person  
};
