#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED
#include "Object.h"
#include "global.h"
#include "MenuTitle.h"
#define CLICK_RAD -(PI / 5)
#define CRITICAL_RAD (PI / 2)

const double rad_unit = (CRITICAL_RAD - CLICK_RAD) / ((critical_velocity - click_velocity) / gravity);

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
    bool isReachGround = false;

    double velocity = 0;
    double acceleration = gravity;

    static float volume;

    // Height limit
    const int BIRD_MAX_HEIGHT = -60;
public:
    Bird();
    virtual ~Bird();
    void Load_move();
    void Draw();
    bool Move(const State& state);
    void MoveInMenu(MenuTitle *&title);
    void Reset();

    void ClickDetected();

};

#endif