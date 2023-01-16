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
        al_destroy_bitmap(img);
    }

    while(!Weapons.empty()){
        delete Weapons.back();
        Weapons.pop_back();
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

    for(auto weapon: Weapons){
        weapon->Draw();
    }
}

void Boss::Move(Pipe* pp){
    counter = (counter + 1 == draw_frequency) ? 0 : counter + 1;

    if(counter == 0){
        sprite_pos = (sprite_pos + 1 == img_count) ? 0 : sprite_pos + 1;
    }

    if(phase == 1){
        ReachPipe = false;
        if(Rect(this->rect->x, this->rect->y + velocity, this->rect->w, this->rect->h).isOverlap(pp->GetLowerPipe()->getRect())){
            this->rect->y = pp->GetLowerPipe()->getY();
            ReachPipe = true;
        }
        else if(Rect(this->rect->x, this->rect->y + velocity, this->rect->w, this->rect->h).isOverlap(pp->GetUpperPipe()->getRect())){
            this->rect->y = pp->GetUpperPipe()->getY() + PIPE_H;
            velocity = 0;
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

void Boss::Attack(Object* target){
    int dx = (target->getX() - this->rect->x) / 5;
    int dy = (target->getY() - this->rect->y) / 5;
    this->Weapons.emplace_back(Weapon(this->rect->x, this->rect->y, dx, dy));
}

bool Boss::WeaponCollide(Object* target){
    for(auto weapon: Weapons){
        if(target->isOverlap(weapon))
            return true;
    }
    return false;
}

void Boss::UpdateWeapons(){
    for(int i=0, end=Weapons.size() ; i<end ; i++){
        Weapons[i]->Move();
        if(Weapons[i]->getX() < -100){
            delete Weapons[i];
            Weapons.erase(Weapons.begin() + i);
            i--;
        }
    }
}

bool Boss::isReachPipe(){
    return ReachPipe;
}

void Boss::UpdatePhase(int NewPhase){
    this->phase = NewPhase;
}

int Boss::GetPhase(){
    return this->phase;
}