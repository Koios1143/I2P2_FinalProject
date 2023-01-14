#ifndef GAMEOVERTITLE_H_INCLUDED
#define GAMEOVERTITLE_H_INCLUDED
#include "Title.h"

class GameOverTitle: public Title
{
public:
    GameOverTitle(int pos_x, int pos_y): Title(pos_x, pos_y, 0, 0) 
    {
        title_img = al_load_bitmap("./img/title/end_title.png");
        this->rect->w = al_get_bitmap_width(title_img);
        this->rect->h = al_get_bitmap_height(title_img);
        this->rect->x -= this->rect->w / 2;
        this->rect->y -= this->rect->h / 2;
    }
};

#endif