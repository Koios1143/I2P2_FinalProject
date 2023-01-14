#ifndef SCOREBOARD_H_INCLUDED
#define SCOREbOARD_H_INCLUDED
#include "Title.h"
#include "global.h"

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

class ScoreBoard: public Title
{
private:
    ALLEGRO_BITMAP *medal_img[4];
    ALLEGRO_FONT *score_font;
    int score = 0, best = 0, medal = 0;
public:
    ScoreBoard(int pos_x, int pos_y): Title(pos_x, pos_y, 0, 0) {
        title_img = al_load_bitmap("./img/title/score.png");
        score_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0);
        char buffer[50];
        for (int i = 0; i < 4; i++) {
            sprintf(buffer, "./img/medal/medal_%d.png", i);
            medal_img[i] = al_load_bitmap(buffer);
        }
        this->rect->w = al_get_bitmap_width(title_img);
        this->rect->h = al_get_bitmap_height(title_img);
        this->rect->x -= this->rect->w / 2;
        this->rect->y -= this->rect->h / 2;
    }
    ~ScoreBoard() {
        for (int i = 0; i < 4; i++) {
            al_destroy_bitmap(medal_img[i]);
        }
    }
    void Reset(int in_score, int in_best) {
        score = in_score, best = in_best;
        if (score <= 10) medal = 0;
        else if (score <= 20) medal = 1;
        else if (score <= 40) medal = 2;
        else medal = 3;
    }
    void Draw() override {
        al_draw_scaled_bitmap(
            title_img,
            0, 0,
            al_get_bitmap_width(title_img),
            al_get_bitmap_height(title_img),
            this->getX(), this->getY(),
            this->getW(), this->getH(), 0
        );
        al_draw_scaled_bitmap(
            medal_img[medal],
            0, 0,
            al_get_bitmap_width(medal_img[medal]),
            al_get_bitmap_height(medal_img[medal]),
            this->getX() + 70, this->getY() + 90,
            al_get_bitmap_width(medal_img[medal]),
            al_get_bitmap_height(medal_img[medal]), 0
        );
        char buf_score[20], buf_best[20];
        sprintf(buf_score, "%d", score);
        sprintf(buf_best, "%d", best);
        al_draw_text(score_font, BLACK, this->getX() + 400, this->getY() + 70, ALLEGRO_ALIGN_RIGHT, buf_score);
        al_draw_text(score_font, BLACK, this->getX() + 400, this->getY() + 150, ALLEGRO_ALIGN_RIGHT, buf_best);
    }
    
};


#endif