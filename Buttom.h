#ifndef BUTTOM_H_INCLUDE
#define BUTTOM_H_INCLUDE

#include "Object.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Buttom: public Object
{
    public:
        // x, y, width, height
        Buttom(int, int, int, int);
        virtual ~Buttom();

        void Draw();
        void ToggleClicked();

        static float volume;
    protected:
        bool isClicked = false;
        ALLEGRO_BITMAP *buttom_img;
        ALLEGRO_SAMPLE *sample;
        ALLEGRO_SAMPLE_INSTANCE *buttom = NULL;
};

#endif