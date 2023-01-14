#ifndef READYTITLE_H_INCLUDED
#define READYTITLE_H_INCLUDED
#include "Title.h"

class ReadyTitle: public Title
{
    ALLEGRO_BITMAP *play_guide = nullptr;
public:
    ReadyTitle(int pos_x, int pos_y): Title(pos_x, pos_y, 0, 0)
    {
        title_img = al_load_bitmap("./img/title/ready_title.png");
        play_guide = al_load_bitmap("./img/play_guide.png");
        this->rect->w = al_get_bitmap_width(title_img);
        this->rect->h = al_get_bitmap_height(title_img);
        this->rect->x -= this->rect->w / 2;
        this->rect->y -= this->rect->h / 2;
    }
    ~ReadyTitle() {
        al_destroy_bitmap(play_guide);
    }
    void Draw() override {
        al_draw_scaled_bitmap(
            title_img,
            0, 0,
            al_get_bitmap_width(title_img),
            al_get_bitmap_height(title_img),
            this->getX(), this->getY(),
            this->getW(), this->getH(), 0
        );
        int width = al_get_bitmap_width(play_guide), height = al_get_bitmap_height(play_guide);
        al_draw_scaled_bitmap(
            play_guide,
            0, 0,
            width, height,
            window_width / 2 - width / 2, window_height / 2 - height / 2,
            width, height, 0
        );
    }
};

#endif