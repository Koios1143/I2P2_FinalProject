#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include"Rect.h"

class Object
{
public:
    Object() {}
    ~Object() {}

    // pure function for drawing object
    virtual void Draw() = 0;

    int getX() { return rect->x; }
    int getY() { return rect->y; }
    int getH() { return rect->h; }
    int getW() { return rect->w; }
    int getCenterX() { return rect->x + rect->w/2; }
    int getCenterY() { return rect->y + rect->h/2; }

    Rect *getRect() const { return rect; }
    bool isOverlap(Object* obj){
        return this->rect->isOverlap(obj->getRect());
    }

protected:
    Rect *rect;
};

#endif // OBJECT_H_INCLUDED
