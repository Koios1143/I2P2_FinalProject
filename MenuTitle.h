#ifndef MENUTITLE_H_INCLUDED
#define MENUTITLE_H_INCLUDED
#include "Title.h"
#define lower_bound (window_height - 650)
#define upper_bound (window_height - 800)
#define UP -1
#define DOWN 1

const int title_draw_frequency = 2;

class MenuTitle: public Title
{
    int direction = -1;
    int counter = 0;
public:
    MenuTitle(int pos_x, int pos_y): Title(pos_x, pos_y, 0, 0) 
    {
        title_img = al_load_bitmap("./img/title/main_title.png");
        this->rect->w = al_get_bitmap_width(title_img);
        this->rect->h = al_get_bitmap_height(title_img);
        this->rect->x -= this->rect->w / 2;
    }
    void Move() 
    {
        counter = (counter + 1) % title_draw_frequency;
        if (counter == 0) {
            rect->y += direction;
            if (rect->y + rect->h > lower_bound || rect->y < upper_bound) direction *= -1; 
        }
    }
};

#endif