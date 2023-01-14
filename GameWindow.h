#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <list>
#include "global.h"
#include "StartButtom.h"
#include "PauseButtom.h"
#include "OkButtom.h"
#include "ResumeButtom.h"
#include "Bird.h"
#include "Pipe.h"
#include "PairPipe.h"
#include "MenuTitle.h"
#include "GameOverTitle.h"
#include "ScoreBoard.h"
#include "ReadyTitle.h"

#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// score to next stage
const int Level_1_Score_Max = 20;

class GameWindow
{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();

    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    void draw_running_map();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);

    // update the position of the ground (move the ground)
    void update_ground_pos() {
        ground_pos_x -= PIPE_dx;
        if (ground_pos_x <= -window_width) ground_pos_x = window_width;
    }

    void groundDraw();
    void scoreDraw();

    void generate_new_pipes();

    inline ALLEGRO_TIMER* &GetTimer() { return this->timer; };
    

public:
    bool initial = true;

private:
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *ground;
    ALLEGRO_BITMAP *background = NULL;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;
    ALLEGRO_FONT *XLarge_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *passSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *hitSound = NULL;

    // Buttoms
    StartButtom *startbuttom = NULL;
    PauseButtom *pausebuttom = NULL;
    OkButtom *okbuttom = NULL;
    ResumeButtom *resumebuttom = NULL;

    // Titles
    MenuTitle *menutitle = nullptr;
    GameOverTitle *endtitle = nullptr;
    ScoreBoard *scoreboard = nullptr;
    ReadyTitle *ready = nullptr;


    // Game state
    State state = MENU;
    int stage = 0;  // record current stage number.
    int score = 0;  // record current number of pipe passed
    int best_score = 0; // record the best score

    Bird *flappyBird;
    
    int mouse_x, mouse_y;
    bool change_state = false;

    // Buttoms selected
    bool selectedStart = 0;
    bool selectedOk = 0;
    bool selectedPause = false;
    bool selectedResume = false;
    bool pause = false;

    bool redraw = false;
    bool mute = false;

    // For pipes to know when to update
    int FPS_count;

    // the upper left corner of ground
    int ground_pos_x;
    std::vector<Pipe*> PIPEs;
    std::vector<Pipe*> Bird_PIPEs;
};

extern GameWindow *FlappyBird;

#endif // MAINWINDOW_H_INCLUDED
