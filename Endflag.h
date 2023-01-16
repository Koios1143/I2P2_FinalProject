#ifndef ENDFLAG_H_INCLUDED
#define ENDFLAG_H_INCLUDED
#include "Object.h"
#include "global.h"

class Endflag: public Object
{
    ALLEGRO_BITMAP *flag_img = nullptr;
public:
    Endflag(int pos_x, int pos_y) {
        flag_img = al_load_bitmap("./img/end_flag.png");
        this->rect = new Rect;
        this->rect->w = al_get_bitmap_width(flag_img);
        this->rect->h = al_get_bitmap_height(flag_img);
        this->rect->x = pos_x + this->rect->w;
        this->rect->y = pos_y - this->rect->h / 2;
    }
    ~Endflag() {
        delete rect;
        al_destroy_bitmap(flag_img);
    }
    void Draw() {
        al_draw_scaled_bitmap(
            flag_img,
            0, 0,
            al_get_bitmap_width(flag_img),
            al_get_bitmap_height(flag_img),
            this->getX(), this->getY(),
            this->getW(), this->getH(), 0
        );
    }
    void Update(int dx, int dy){
        this->rect->UpdatePos(dx, dy);
    }
};

#endif