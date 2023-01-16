#include "Boss.h"

const int draw_frequency = 2;

float Boss::volume = 2.0;

Boss::Boss(){
    counter = 0;
    sprite_pos = 0;
    img_count = 4;

    rect = new Rect();

    ReachPipe = true;

    //sample = 
    //attackSound = 
    // al_set_sample_instance_playmode(wingSound, ALLEGRO_PLAYMODE_ONCE);
    // al_attach_sample_instance_to_mixer(wingSound, al_get_default_mixer());
    // al_set_sample_instance_gain(wingSound, Bird::volume);

}

Boss::~Boss(){
    while(!Img.empty()){
        ALLEGRO_BITMAP* img = Img.back();
        Img.pop_back();
        algif_destroy_bitmap(img);
    }

    delete rect;

    //al_destroy_sample_instance(wingSound);
    //al_destroy_sample(sample);
}

void Boss::Load_move(){
    
    rect->x = window_width * 3 / 4;
    rect->y = window_height / 3;
    rect->w = al_get_bitmap_width(Img[0]);
    rect->h = al_get_bitmap_height(Img[0]);
}

void Boss::Draw(){
    if(Img[sprite_pos] == NULL)
        return;
    
    al_draw_rotated_bitmap(Img[sprite_pos], rect->w / 2, rect->h / 2, rect->x + rect->w / 2, rect->y + rect->h / 2, 0, 0);
}

void Boss::Move(){
    counter = (counter + 1 == draw_frequency) ? 0 : counter + 1;

    if(counter == 0){
        sprite_pos = (sprite_pos + 1 == img_count) ? 0 : sprite_pos + 1;
    }

    if(phase == 1){
        if(this->rect->y + velocity >= INITIAL_Y){
            this->rect->y = INITIAL_Y;
            ReachPipe = true;
        }
        else if(this->rect->y + velocity < CEILING){
            this->rect->y = CEILING;
            velocity = 0;
            ReachPipe = false;
        }
        else{
            this->rect->y += velocity;
        }
    }
    else{
        this->rect->y += velocity;
    }
    if(velocity < critical_velocity) velocity += acceleration;
}

void Boss::Jump(){
    if(phase == 1){
        this->velocity = click_velocity;
    }
    else{
        this->velocity = 2 * click_velocity;
    }
}

void Boss::Attack(int dx, int dy){

}

bool Boss::isReachPipe(){
    return ReachPipe;
}