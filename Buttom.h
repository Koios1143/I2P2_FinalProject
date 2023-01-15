#ifndef BUTTOM_H_INCLUDED
#define BUTTOM_H_INCLUDED

#include "Object.h"
#include "global.h"

class Buttom: public Object
{
    public:
        // x, y, width, height
        Buttom(int, int, int, int);
        virtual ~Buttom();

        void Draw();
        void ToggleClicked();
        ALLEGRO_SAMPLE_INSTANCE *&getSample() { return buttom; }
        bool mouse_hover(int mouse_x, int mouse_y);

        static float volume;
    protected:
        bool isClicked = false;
        ALLEGRO_BITMAP *buttom_img;
        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE_INSTANCE *buttom = NULL;
};

#endif