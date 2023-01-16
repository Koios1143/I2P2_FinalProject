#include "Weapon.h"

Weapon::Weapon(int x, int y, int vx, int vy){
    printf("Construct new weapon\n");
    rect = new Rect(x, y, WEAPON_W, WEAPON_H);
    this->velocity_x = vx;
    this->velocity_y = vy;
    WeaponImg = al_load_bitmap("./img/boss/weapon.png");
}

Weapon::~Weapon(){
    delete rect;
    al_destroy_bitmap(WeaponImg);
}

void Weapon::Draw(){
    al_draw_rotated_bitmap(this->WeaponImg, this->rect->w / 2, this->rect->h / 2, this->rect->center.x, this->rect->center.y, 0, 0);
}

void Weapon::Move(){
    this->rect->UpdatePos(this->velocity_x, this->velocity_y);
}