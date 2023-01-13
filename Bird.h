#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED
#include "Object.h"
#include "global.h"

class Bird: public Object
{
    std::vector<ALLEGRO_BITMAP*> flyImg;
    ALLEGRO_SAMPLE_INSTANCE *wingSound = nullptr;
    ALLEGRO_SAMPLE *sample = nullptr;

    // animation counter
    int counter;
    // animation image
    int sprite_pos;
    int img_count;

    // check the gameover condition
    bool ishit = false;

    static float volume;
public:
    Bird();
    ~Bird();
    void Load_move();
    void Draw();
    bool Move();
    void Reset();

};




#endif