#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED
#define PI 3.1415926

#include "Object.h"
#include "global.h"

class Pipe: public Object
{
    public:
        // x, y, angle
        Pipe(int, int, double);
        virtual ~Pipe();

        void Draw();

    protected:
        ALLEGRO_BITMAP *buttom_img;
};

#endif