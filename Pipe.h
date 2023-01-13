#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include "Object.h"
#include "global.h"

const int PIPE_W = 101;
const int PIPE_H = 642;
const int GAP_LEN = 200;
const int PIPE_RAND_MIN = 80;
const int PIPE_RAND_MAX = 500;

const int PIPE_dx = 10;

class Pipe: public Object
{
    public:
        // x, y, angle
        Pipe(int, int, double);
        virtual ~Pipe();
        void Draw();

        void update_pos(int, int);

    protected:
        ALLEGRO_BITMAP *pipe_img = al_load_bitmap("./img/upward_pipe.png");
        double angle;
};

#endif