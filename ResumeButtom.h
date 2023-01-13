#ifndef RESUMEBUTTOM_H_INCLUDED
#define RESUMEBUTTOM_H_INCLUDED
#include "Buttom.h"

class ResumeButtom: public Buttom{
    public:
        ResumeButtom(int pos_x, int pos_y): Buttom(pos_x, pos_y, 0, 0){
            buttom_img = al_load_bitmap("./img/buttom/buttom_resume.png");
            this->rect->w = al_get_bitmap_width(buttom_img);
            this->rect->h = al_get_bitmap_height(buttom_img);
            this->rect->x -= this->rect->w / 2;
            this->rect->y -= this->rect->h / 2;
        }
};

#endif