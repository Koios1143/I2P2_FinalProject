#ifndef BIRD_H_INCLUDED
#define BIRD_H_INCLUDED
#include "Object.h"
#include "global.h"
#include "MenuTitle.h"
#define click_velocity -12
#define gravity 0.8
#define critical_velocity 14


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
    ~Bird();
    void Load_move();
    void Draw();
    bool Move(const State& state);
    void MoveInMenu(MenuTitle *&title);
    void Reset();

    void ClickDetected();

};

#endif