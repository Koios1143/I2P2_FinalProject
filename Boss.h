#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "Object.h"
#include "global.h"
#define ATTACK_VELOCITY 10
#define INITIAL_Y (window_height / 3)
#define CEILING = (INITIAL_Y - 115)

class Boss: public Object
{
    public:
        Boss();
        virtual ~Boss();
        void Load_move();
        void Draw();
        void Move();
        void Jump();
        void UpdatePhase(int);
        void Attack(int, int);
        bool isReachPipe();

        int counter;
        int sprite_pos;
        int img_count;

        double velocity = click_velocity;
        double acceleration = gravity;
    
        static float volume;

    protected:
        std::vector<ALLEGRO_BITMAP*> Img;
        ALLEGRO_SAMPLE_INSTANCE *attackSound = NULL;
        ALLEGRO_SAMPLE *sample = NULL;

        // phase == 1: keep jumping
        // phase == 2: collide with pipe XDD
        int phase = 1;
        bool ReachPipe;
}

#endif