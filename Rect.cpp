#include "Rect.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

double Heron(double a, double b, double c){
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double distance(dot a, dot b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool Rect::isOverlap(Rect *rect_1, Rect *rect_2){
    if(min(rect_1->x + rect_1->w, rect_2->x + rect_2->w) < max(rect_1->x, rect_2->x)){
        return false;
    }
    if(min(rect_1->y + rect_1->h, rect_2->y + rect_2->h) < max(rect_1->y, rect_2->y)){
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