#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED
#include "Object.h"
#include "global.h"

class Bird: public Object
{
    ALLEGRO_BITMAP *bird_img[3];
    ALLLEGRO_SAMPLE_INSTANCE *wingSound = nullptr;
    AllEGRO_SAMPLE *sample = nullptr;
public:
    



};




#endif