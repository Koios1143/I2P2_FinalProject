#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "Object.h"
#include "Weapon.h"
#include "global.h"
#include "PairPipe.h"
#define ATTACK_VELOCITY 10
#define INITIAL_Y (window_height / 3)
#define CEILING = (INITIAL_Y - 115)
// Anus Overflow
#define RP 40

class Boss: public Object
{
    public:
        Boss();
        virtual ~Boss();
        void Load_move(int, int);
        void Draw();
        void Move(Pipe*);
        void Jump();
        void UpdatePhase(int);
        int GetPhase();
        int GetWeaponSize();
        void Attack(Object*);

        bool isReachPipe();
        bool WeaponCollide(Object*);
        void UpdateWeapons();

        double velocity = click_velocity;
        double acceleration = gravity;
    
        static float volume;

    protected:
        ALLEGRO_BITMAP* Img;
        ALLEGRO_SAMPLE_INSTANCE *attackSound = NULL;
        ALLEGRO_SAMPLE *sample = NULL;

        // phase == 1: keep jumping
        // phase == 2: collide with pipe XDD
        int phase = 1;
        bool ReachPipe;

        std::vector<Weapon*> Weapons;
};

#endif