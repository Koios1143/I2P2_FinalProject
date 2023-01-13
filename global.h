#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro_font.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <cmath>
#include <iostream>
#include "algif5/src/algif.h"
#include <cstring>
#include <vector>

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 990
#define window_height 990
#define ground_height (window_height - 200)
#define field_width 600
#define field_height 600


#define NumOfGrid (field_width / grid_width) * (field_height / grid_height)



#endif // GLOBAL_H_INCLUDED
