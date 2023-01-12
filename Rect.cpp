#include "Rect.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

bool Rect::isOverlap(Rect *rect_1, Rect *rect_2){
    if(min(rect_1->x + rect_1->w, rect_2->x + rect_2->w) < max(rect_1->x, rect_2->x)){
        return false;
    }
    if(min(rect_1->y + rect_1->h, rect_2->y + rect_2->h) < max(rect_1->y, rect_2->y)){
        return false;
    }
    return true;
}