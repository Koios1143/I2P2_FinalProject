#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include "Object.h"
#include "global.h"

const int PIPE_W = 101;
const int PIPE_H = 642;
const int PIPE_dx = 10;
const int GAP_LEN = 230;
const int PIPE_RAND_MIN = 50;
const int PIPE_RAND_MAX = 470;

class Pipe: public Object
{
    public:
        // x, y, angle
        Pipe(int pos_x, int pos_y, double angle){
            this->rect = new Rect(pos_x, pos_y, PIPE_W, PIPE_H);
            this->angle = angle;
        }
        virtual ~Pipe(){
            delete rect;
            al_destroy_bitmap(pipe_img);
        }
        void Draw(){
            al_draw_rotated_bitmap(this->pipe_img, this->rect->w / 2, this->rect->h / 2, this->rect->center.x, this->rect->center.y, this->angle, 0);
        }

        void update_pos(int dx, int dy){
            this->rect->x += dx;
            this->rect->y += dy;
            for(int i=0 ; i<4 ; i++){
                this->rect->points[i].x += dx;
                this->rect->points[i].y += dy;
            }
            this->rect->center.x += dx;
            this->rect->center.y += dy;
        }

    protected:
        ALLEGRO_BITMAP *pipe_img = al_load_bitmap("./img/upward_pipe.png");
        double angle;
};

#endif