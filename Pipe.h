#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

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
        ALLEGRO_BITMAP *pipe_img = al_load_bitmap("./img/upward_pipe.png");
        double angle;
};

#endif