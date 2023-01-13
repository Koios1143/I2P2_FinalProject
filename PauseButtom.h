#ifndef PAUSEBUTTOM_H_INCLUDED
#define PAUSEBUTTOM_H_INCLUDED
#include "Buttom.h"

class PauseButtom: public Buttom{
    public:
        PauseButtom(int pos_x, int pos_y): Buttom(pos_x, pos_y, 0, 0){
            buttom_img = al_load_bitmap("./img/buttom/buttom_pause.png");
            this->rect->w = al_get_bitmap_width(buttom_img);
            this->rect->h = al_get_bitmap_height(buttom_img);
        }
};

#endif