#ifndef RECT_H_INCLUDED
#define RECT_H_INCLUDED

class Rect
{
public:
    Rect() {}

    Rect(int x, int y, int w, int h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    static bool isOverlap(Rect *, Rect *);

    int w, h;
    int x, y;
};

#endif // RECT_H_INCLUDED
