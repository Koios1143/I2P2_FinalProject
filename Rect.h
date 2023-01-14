#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED

#include "global.h"

class Rect
{
public:
    Rect() {}

    Rect(int x, int y, int w, int h, double angle = 0)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->angle = angle;

        for(int i=0 ; i<4 ; i++){
            points[i] = dot{x + rect_dx[i] * w, y + rect_dy[i] * h};
        }
        center = dot{x + w / 2, y + h / 2};
        for(int i=0 ; i<4 ; i++){
            double x = points[i].x;
            double y = points[i].y;
            points[i] = dot{int(x * cos(angle) - y * sin(angle)), int(x * sin(angle) + y * cos(angle))};
        }
    }

    static bool isOverlap(Rect *, Rect *);
    static bool isRotateOverlap(Rect *, Rect *);

    int w, h;
    int x, y;
    double angle;
    dot points[4];
    dot center;
};

#endif // RECT_H_INCLUDED
