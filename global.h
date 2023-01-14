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
#include <time.h>
#include "algif5/src/algif.h"
#include <cstring>
#include <vector>

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 990
#define window_height 990
#define ground_height (window_height - 150)
#define field_width 600
#define field_height 600

#define PI 3.1415926
#define MinimumPipeHeight 80
#define MaximumPipeHeight ground_height - 80

#define NumOfGrid (field_width / grid_width) * (field_height / grid_height)
#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))

// the state type
enum State{ MENU = 0, GET_READY, IN_GAME, GAME_OVER };

const int rect_dx[] = {0, 1, 1, 0};
const int rect_dy[] = {0, 0, 1, 1};

struct dot{
    int x;
    int y;
};

#endif // GLOBAL_H_INCLUDED
