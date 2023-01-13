#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED

#include "Object.h"
#include "global.h"

class Title: public Object
{
public:
    Title(int, int ,int ,int);
    virtual ~Title();

    void Draw();

protected:
    ALLEGRO_BITMAP *title_img;
};



#endif