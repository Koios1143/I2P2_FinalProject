#include "Buttom.h"

float Buttom::volume = 1.0;

Buttom::Buttom(int pos_x, int pos_y, int width, int height){
    this->rect = new Rect(pos_x, pos_y, width, height);

    sample = al_load_sample("./sound/click.wav");
    buttom = al_create_sample_instance(sample);
}

Buttom::~Buttom(){
    delete rect;

    al_destroy_bitmap(buttom_img);
    al_destroy_sample_instance(buttom);
    al_destroy_sample(sample);
}

void Buttom::Draw(){
    al_draw_scaled_bitmap(
        buttom_img,
        this->getX(), this->getY(),
        al_get_bitmap_width(buttom_img),
        al_get_bitmap_height(buttom_img),
        this->getX(), this->getY(),
        this->getW(), this->getH(),
        0
    );
}

void Buttom::ToggleClicked(){ 
    isClicked = !isClicked;

    // Play Clicked sound effect
    al_set_sample_instance_playmode(buttom, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(buttom, al_get_default_mixer());
    al_set_sample_instance_gain(buttom, Buttom::volume);
    al_play_sample_instance(buttom);
}

bool Buttom::mouse_hover(int mouse_x, int mouse_y) {
    if (mouse_x <= rect->x + rect->w && mouse_x >= rect->x && mouse_y >= rect->y && mouse_y <= rect->y + rect->h) {
        ToggleClicked();
        return true;
    }
    return false;
}