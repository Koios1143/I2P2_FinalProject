#include "Pipe.h"

Pipe::Pipe(int pos_x, int pos_y, double angle){
    this->rect = new Rect(pos_x, pos_y, al_get_bitmap_width(pipe_img), al_get_bitmap_height(pipe_img));
    this->angle = angle;
}

Pipe::~Pipe(){
    delete rect;
    al_destroy_bitmap(pipe_img);
}

void Pipe::Draw(){
    al_draw_rotated_bitmap(this->w / 2, this->h / 2, this->getCenterX(), this->getCenterY(), angle);
}

