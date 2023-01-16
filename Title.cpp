#include "Title.h"

Title::Title(int posx, int posy, int width, int height)
{
    this->rect = new Rect(posx, posy, width, height);
}

Title::~Title()
{
    delete rect;
    al_destroy_bitmap(title_img);
}

void Title::Draw()
{
    al_draw_scaled_bitmap(
        title_img,
        0, 0,
        al_get_bitmap_width(title_img),
        al_get_bitmap_height(title_img),
        this->getX(), this->getY(),
        this->getW(), this->getH(),
        0
    );
}