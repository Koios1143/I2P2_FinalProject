#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include "Object.h"
#include "global.h"

const int PIPE_W = 101;
const int PIPE_H = 642;
const int PIPE_dx = 10;
const int PIPE_RAND_MIN = 50;
const int PIPE_RAND_MAX = 470;

class Pipe: public Object
{
    public:
        // x, y, angle, velocity, type(0: upward, 1: downward)
        Pipe(int pos_x, int pos_y, double angle, int velocity = 0, int type = 0){
            this->rect = new Rect(pos_x, pos_y, PIPE_W, PIPE_H);
            this->angle = angle;
            this->velocity = velocity;
            if(type == 0) this->pipe_img = al_load_bitmap("./img/upward_pipe.png");
            else this->pipe_img = al_load_bitmap("./img/downward_pipe.png");
        }
        virtual ~Pipe(){
            delete rect;
            al_destroy_bitmap(pipe_img);
        }
        void Draw(){
            //printf("Draw (%d, %d)\n", this->rect->center.x, this->rect->center.y);
            al_draw_rotated_bitmap(this->pipe_img, this->rect->w / 2, this->rect->h / 2, this->rect->center.x, this->rect->center.y, this->angle, 0);
        }

        virtual void UpdatePos(int dx, int dy){
            // printf("velocity: %d\n", dy);
            this->rect->UpdatePos(dx, dy);
        }

        bool CollideWith(Object* obj){
            return this->rect->isRotateOverlap(this->rect, obj->getRect());
        }

    protected:
        ALLEGRO_BITMAP *pipe_img = NULL;
        double angle;
        int velocity;
};

#endif