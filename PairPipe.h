#ifndef PAIRPIPE_H_INCLUDED
#define PAIRPIPE_H_INCLUDED
#include "Object.h"
#include "Pipe.h"
#include "global.h"

const int GAP_LEN = 230;
const int PIPE_VELOCITY_MIN = 2;
const int PIPE_VELOCITY_MAX = 5;
const int PIPE_CENTER_MIN = 180;
const int PIPE_CENTER_MAX = ground_height - 180;

class PairPipe: public Pipe
{
    public:
        // x, y, angle
        PairPipe(int center_x, int center_y, double angle, int velocity = 0, int type = 0): Pipe(
            center_x - PIPE_W / 2, center_y - GAP_LEN / 2 - PIPE_H,
            angle, velocity, type, 1
        ){
            this->velocity = velocity;
            this->type = type;
            if(type == 0){
                this->lower_pipe = new Pipe(center_x - PIPE_W / 2, center_y + GAP_LEN / 2, angle, velocity, 0);
                this->upper_pipe = new Pipe(center_x - PIPE_W / 2, center_y - GAP_LEN / 2 - PIPE_H, angle, velocity, 1);
            }
            else{
                this->lower_pipe = new Pipe(center_x - PIPE_W / 2, center_y + GAP_LEN / 2, angle, velocity, 2);
                this->upper_pipe = new Pipe(center_x - PIPE_W / 2, center_y - GAP_LEN / 2 - PIPE_H, angle, velocity, 3);
            }
        }
        
        virtual ~PairPipe(){
            delete upper_pipe;
            delete lower_pipe;
        }

        void Draw() override{
            upper_pipe->Draw();
            lower_pipe->Draw();
        }

        void UpdatePos(int dx, int dy) override{
            if(velocity < 0){
                if(max(upper_pipe->getRect()->points[0].y, upper_pipe->getRect()->points[2].y) + velocity < MinimumPipeHeight){
                    velocity = -velocity;
                }
            }
            else{
                if(min(lower_pipe->getRect()->points[0].y, lower_pipe->getRect()->points[2].y) + velocity > MaximumPipeHeight){
                    velocity = -velocity;
                }
            }
            lower_pipe->UpdatePos(dx, velocity);
            upper_pipe->UpdatePos(dx, velocity);
            this->rect->UpdatePos(this->lower_pipe->getRect()->x - this->rect->x, velocity);
        }

        bool CollideWith(Object* obj){
            return this->upper_pipe->CollideWith(obj) || this->lower_pipe->CollideWith(obj);
        }

        Pipe* GetUpperPipe() override{
            return this->upper_pipe;
        }

        Pipe* GetLowerPipe() override{
            return this->lower_pipe;
        }

    protected:
        double angle;
        int velocity;
        Pipe* upper_pipe = NULL;
        Pipe* lower_pipe = NULL;
};

#endif