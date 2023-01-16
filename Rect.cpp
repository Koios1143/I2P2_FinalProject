#include "Rect.h"

double Heron(double a, double b, double c){
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double distance(dot a, dot b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool Rect::isOverlap(Rect *rect){
    if(min(this->x + this->w, rect->x + rect->w) < max(this->x, rect->x)){
        return false;
    }
    if(min(this->y + this->h, rect->y + rect->h) < max(this->y, rect->y)){
        return false;
    }
    return true;
}

bool Rect::isRotateOverlap(Rect *rect_1, Rect *rect_2){
    // Rect1 -> Rect2
    int R2_Area = rect_2->w * rect_2->h;
    for(int i=0 ; i<4 ; i++){
        int cnt = 0;
        for(int j=0, k=1 ; j <= 3 ; j++, k = (k + 1) % 4){
            double a = distance(rect_1->points[i], rect_2->points[j]);
            double b = distance(rect_1->points[i], rect_2->points[k]);
            double c = distance(rect_2->points[j], rect_2->points[k]);
            cnt += Heron(a, b , c);
        }
        if(cnt <= R2_Area){
            return true;
        }
    }

    // Rect2 -> Rect1
    int R1_Area = rect_1->w * rect_1->h;
    for(int i=0 ; i<4 ; i++){
        int cnt = 0;
        for(int j=0, k=1 ; j <= 3 ; j++, k = (k + 1) % 4){
            double a = distance(rect_2->points[i], rect_1->points[j]);
            double b = distance(rect_2->points[i], rect_1->points[k]);
            double c = distance(rect_1->points[j], rect_1->points[k]);
            cnt += Heron(a, b , c);
        }
        if(cnt <= R1_Area){
            return true;
        }
    }

    return false;
}