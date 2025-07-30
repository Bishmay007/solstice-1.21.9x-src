#include "Options.hpp"  
#include <src/SDK/SigManager.hpp>  
#include <xmmintrin.h>



int* Options::mThirdPersons() {  
    return reinterpret_cast<int*>(MemUtils::callFastcall<void*>(SigManager::Fistpr));  

}  
/*
IntOption* Options::mThirdPerson() {  
    IntOption* option = new IntOption();  
    option->value = *mThirdPersons();  
    return option;  
}  */
/*
FloatOption* Options::mGfxGamma() {  
    return MemUtils::callFastcall<FloatOption*>(SigManager::GammaSig);  
}*/
