#ifndef WEAPON_H_INCLUDED
#define WEAPON_H_INCLUDED
#include "Object.h"
#include "global.h"

const int WEAPON_W = 0;
const int WEAPON_H = 0;

class Weapon: public Object
{
    public:
        Weapon(int, int, int, int);
        virtual ~Weapon();
        void Draw();
        void Move();

        double velocity_x;
        double velocity_y;
    protected:
        ALLEGRO_BITMAP* WeaponImg = NULL;
};

#endif