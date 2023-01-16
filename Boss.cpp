#include "Boss.h"

const int draw_frequency = 2;

float Boss::volume = 2.0;

Boss::Boss(){
    rect = new Rect();

    ReachPipe = true;

    sample = al_load_sample("./sound/shoot.wav");
    attackSound = al_create_sample_instance(sample);

    al_set_sample_instance_playmode(attackSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(attackSound, al_get_default_mixer());
    al_set_sample_instance_gain(attackSound, Boss::volume);

}

Boss::~Boss(){
    al_destroy_bitmap(Img);

    while(!Weapons.empty()){
        delete Weapons.back();
        Weapons.pop_back();
    }

    delete rect;

    al_destroy_sample_instance(attackSound);
    al_destroy_sample(sample);
}

void Boss::Load_move(int x, int y){
    Img = al_load_bitmap("./img/boss/chicken.png");

    rect->w = al_get_bitmap_width(Img);
    rect->h = al_get_bitmap_height(Img);
    rect->x = x;
    rect->y = y - rect->h;
}

void Boss::Draw(){
    if(Img == NULL)
        return;
    
    al_draw_rotated_bitmap(Img, rect->w / 2, rect->h / 2, rect->x + rect->w / 2, rect->y + rect->h / 2, 0, 0);

    for(auto weapon: Weapons){
        weapon->Draw();
    }
}

void Boss::Move(Pipe* pp){
    this->rect->UpdatePos(pp->getRect()->x - this->rect->x, 0);
    if(phase == 1){
        ReachPipe = false;
        if(Rect(this->rect->x, this->rect->y + velocity, this->rect->w, this->rect->h).isOverlap(pp->GetLowerPipe()->getRect())){
            this->rect->UpdatePos(0, pp->GetLowerPipe()->getY() - this->getRect()->h - this->rect->y);
            ReachPipe = true;
        }
        else if(Rect(this->rect->x, this->rect->y + velocity, this->rect->w, this->rect->h).isOverlap(pp->GetUpperPipe()->getRect())){
            this->rect->UpdatePos(0, pp->GetUpperPipe()->getY() + PIPE_H - this->rect->y + 10);
            velocity = 0;
        }
        else{
            this->rect->UpdatePos(0, velocity);
        }
    }
    else if(phase == 2){
        this->velocity = 100;
        this->rect->UpdatePos(0, velocity);
        if(Rect(this->rect->x, this->rect->y + velocity, this->rect->w, this->rect->h).isOverlap(pp->GetUpperPipe()->getRect())){
            // al_set_sample_instance_position(attackSound, 0);
            // al_play_sample_instance(attackSound);
            phase = 3;
        }
    }
    if(velocity < critical_velocity) velocity += acceleration;
}

void Boss::Jump(){
    if(phase == 1){
        this->velocity = click_velocity;
    }
}

void Boss::Attack(Object* target){
    int dx = (target->getX() - this->rect->x) / 40;
    int dy = (target->getY() - this->rect->y) / 40;
    this->Weapons.emplace_back(new Weapon(this->rect->x, this->rect->y, dx, dy));
    al_set_sample_instance_position(attackSound, 0);
    al_play_sample_instance(attackSound);
    
}

bool Boss::WeaponCollide(Object* target){
    for(auto weapon: Weapons){
        if(target->isOverlap(weapon))
            return true;
    }
    return false;
}

void Boss::UpdateWeapons(){
    for(int i=0, end=Weapons.size() ; i<end && i<Weapons.size() ; i++){
        Weapons[i]->Move();
        if(Weapons[i]->getRect()->x < -100){
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

int Boss::GetWeaponSize(){
    return this->Weapons.size();
}