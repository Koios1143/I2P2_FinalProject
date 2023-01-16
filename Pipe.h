#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED

#include "Object.h"
#include "global.h"

const int PIPE_W = 101;
const int PIPE_H = 642;
const int PIPE_dx = 7;
const int PIPE_RAND_MIN = 50;
const int PIPE_RAND_MAX = 470;
const int MAXIMUM_BOSS_PIPE_X = window_width * 2 / 3;
const int MAXIMUM_LAST_PIPE_X = window_width / 4;

class Pipe: public Object
{
    public:
        // x, y, angle, velocity, type(0: upward, 1: downward)
        Pipe(int pos_x, int pos_y, double angle, int velocity = 0, int type = 0, int MultiPipe = 0){
            this->rect = new Rect(pos_x, pos_y, PIPE_W, PIPE_H);
            this->angle = angle;
            this->velocity = velocity;
            this->MultiPipe = MultiPipe;
            this->type = type;
            if(type == 0 || type == 4) this->pipe_img = al_load_bitmap("./img/upward_pipe.png");
            else if(type == 1 || type == 5) this->pipe_img = al_load_bitmap("./img/downward_pipe.png");
            else if(type == 2) this->pipe_img = al_load_bitmap("./img/upward_boss_pipe.png");
            else this->pipe_img = al_load_bitmap("./img/downward_boss_pipe.png");
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
            if(type == 0 || type == 1)
                this->rect->UpdatePos(dx, dy);
            else if(type == 2 || type == 3){
                if(this->rect->x + dx < MAXIMUM_BOSS_PIPE_X){
                    this->rect->UpdatePos(MAXIMUM_BOSS_PIPE_X - this->rect->x, dy);
                }
                else{
                    this->rect->UpdatePos(dx, dy);
                }
            }
            else{
                if(this->rect->x == MAXIMUM_LAST_PIPE_X){
                    if(this->type == 4)
                        this->rect->UpdatePos(0, -1);
                    else
                        this->rect->UpdatePos(0, 1);
                }
                else if(this->rect->x + dx < MAXIMUM_LAST_PIPE_X){
                    this->rect->UpdatePos(MAXIMUM_LAST_PIPE_X - this->rect->x, dy);
                }
                else{
                    this->rect->UpdatePos(dx, dy);
                }
            }
        }

        bool CollideWith(Object* obj){
            return this->rect->isRotateOverlap(this->rect, obj->getRect());
        }

        virtual Pipe* GetUpperPipe(){
            return NULL;
        }

        virtual Pipe* GetLowerPipe(){
            return NULL;
        }

        int GetType(){
            return this->type;
        }

        void UpdateType(int type){
            this->type = type;
        }

    int MultiPipe = 0;
    protected:
        ALLEGRO_BITMAP *pipe_img = NULL;
        double angle;
        int velocity;
        int type;
};

#endif