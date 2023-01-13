#include "Pipe.h"

Pipe::Pipe(int pos_x, int pos_y, double angle){
    this->rect = new Rect(pos_x, pos_y, PIPE_W, PIPE_H);
    this->angle = angle;
}

Pipe::~Pipe(){
    delete rect;
    al_destroy_bitmap(pipe_img);
}

void Pipe::Draw(){
    al_draw_rotated_bitmap(this->pipe_img, this->rect->w / 2, this->rect->h / 2, this->getCenterX(), this->getCenterY(), this->angle, 0);
}

void Pipe::update_pos(int pos_x, int pos_y){
    this->rect->x = pos_x;
    this->rect->y = pos_y;
}