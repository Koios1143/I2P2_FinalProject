#include "Bird.h"
#include "GameWindow.h"

// set counter frequency of drawing moving animation
const int draw_frequency = 2;

float Bird::volume = 2.0;

Bird::Bird()
{
    counter = 0;
    sprite_pos = 0;
    img_count = 4;

    rect = new Rect;

    sample = al_load_sample("./sound/sfx_wing.wav");
    wingSound = al_create_sample_instance(sample);

    al_set_sample_instance_playmode(wingSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(wingSound, al_get_default_mixer());
    al_set_sample_instance_gain(wingSound, Bird::volume);
}

Bird::~Bird()
{
    for (int i = 0; i < flyImg.size(); i++)
    {
        ALLEGRO_BITMAP *img = flyImg[i];

        flyImg.erase(flyImg.begin() + i);

        i--;
        al_destroy_bitmap(img);
    }
    flyImg.clear();

    delete rect;

    al_destroy_sample_instance(wingSound);
    al_destroy_sample(sample);

}

void Bird::Load_move()
{
    char buffer[50];

    for (int i = 0; i < 4; i++) 
    {
        ALLEGRO_BITMAP *img;
        sprintf(buffer, "./img/bird/bird_%d.png", i);

        img = al_load_bitmap(buffer);
        if (img) {
            flyImg.push_back(img);
        }
    }

    rect->x = window_width / 4;
    rect->y = window_height / 3;
    rect->w = al_get_bitmap_width(flyImg[0]);
    rect->h = al_get_bitmap_height(flyImg[0]);
}

void Bird::Reset()
{
    rect->x = window_width / 4;
    rect->y = window_height / 3;
    rect->w = al_get_bitmap_width(flyImg[0]);
    rect->h = al_get_bitmap_height(flyImg[0]);

    velocity = 0;
}

void Bird::Draw()
{
    int width, height;
    int offset = 0;

    if(!flyImg[sprite_pos])
        return;

    al_draw_bitmap(flyImg[sprite_pos], rect->x, rect->y, 0);

}

bool Bird::Move()
{
    counter = (counter + 1) % draw_frequency;

    if (counter == 0) {
        sprite_pos = (sprite_pos + 1) % img_count;
    }

    if (!isReachGround){
        rect->y += velocity;
        // Restrict Height
        rect->y = max(rect->y, BIRD_MAX_HEIGHT);
    }
    if (rect->y + rect->h > ground_height) isReachGround = true;

    if (velocity < critical_velocity) velocity += acceleration;

    if (isReachGround) {
        isReachGround = false;
        return true;
    }

    return false;
}

void Bird::MoveInMenu(MenuTitle *&title)
{
    counter = (counter + 1) % draw_frequency;

    if (counter == 0) {
        sprite_pos = (sprite_pos + 1) % img_count;
    }

    rect->x = title->getX() + title->getW() + 30;
    rect->y = title->getY() + 10;
}

void Bird::ClickDetected()
{
    if (al_get_timer_started(FlappyBird->GetTimer())) {
        al_set_sample_instance_position(wingSound, 0);
        al_play_sample_instance(wingSound);
    }
    
    isReachGround = false;
    velocity = click_velocity;
}