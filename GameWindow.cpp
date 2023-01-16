#include "GameWindow.h"

#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

int randint(int L, int R){
    if(L > R) std::swap(L, R);
    return rand() % (R - L + 1) + L;
}

void GameWindow::game_init()
{
    icon = al_load_bitmap("./img/Flappy_Bird_icon.png");
    background = al_load_bitmap("./img/background/background_night.png");
    ground = al_load_bitmap("./img/ground.png");

    // Initialize Buttoms
    startbuttom = new StartButtom(window_width/2, window_height-250);
    pausebuttom = new PauseButtom(100, 100);
    resumebuttom = new ResumeButtom(100, 100);
    okbuttom = new OkButtom(window_width/2, window_height-200);

    // Initialize Titles
    menutitle = new MenuTitle(window_width/2 - 30, upper_bound);
    endtitle = new GameOverTitle(window_width/2, upper_bound + 30);
    scoreboard = new ScoreBoard(window_width/2, window_height/2);
    ready = new ReadyTitle(window_width/2, upper_bound);

    al_set_window_position(display, 250, 0);
    al_set_window_title(display, "Flappy Bird");
    al_set_display_icon(display, icon);
    al_reserve_samples(3);
    
    // Initialize some Samples
    sample = al_load_sample("./sound/sfx_point.wav");
    passSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(passSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(passSound, al_get_default_mixer());
    sample = al_load_sample("./sound/sfx_die.wav");
    dieSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(dieSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(dieSound, al_get_default_mixer());
    sample = al_load_sample("./sound/sfx_hit.wav");
    hitSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(hitSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(hitSound, al_get_default_mixer());
    sample = al_load_sample("./sound/menubgm.wav");
    menubgm = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(menubgm, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(menubgm, al_get_default_mixer());
    sample = al_load_sample("./sound/gamebgm.wav");
    gamebgm = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(gamebgm, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_speed(gamebgm, 1.0);
    al_set_sample_instance_gain(gamebgm, 0.5);
    al_attach_sample_instance_to_mixer(gamebgm, al_get_default_mixer());
    sample = al_load_sample("./sound/sfx_swooshing.wav");
    change = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(change, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(change, al_get_default_mixer());


    std::cout << "Game Initialized!\n";
}

void GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);

    al_destroy_bitmap(icon);
    al_destroy_bitmap(background);

    // Delete Bird
    if (flappyBird) delete flappyBird;
    if (flappyBoss) delete flappyBoss;
    // Delete Buttoms
    if (startbuttom) delete startbuttom;
    if (pausebuttom) delete pausebuttom;
    if (resumebuttom) delete resumebuttom;
    if (okbuttom) delete okbuttom;
    // Delete Title
    if (menutitle) delete menutitle;
    if (endtitle) delete endtitle;
    if (scoreboard) delete scoreboard;
    // Delete Pipes
    while(!PIPEs.empty()){
        delete PIPEs.back();
        PIPEs.pop_back();
    }
    while(!Bird_PIPEs.empty()){
        delete Bird_PIPEs.back();
        Bird_PIPEs.pop_back();
    }
    // Delete Sounds
    al_destroy_sample(sample);
    al_destroy_sample_instance(passSound);
    al_destroy_sample_instance(dieSound);
    al_destroy_sample_instance(hitSound);
    al_destroy_sample_instance(menubgm);
    al_destroy_sample_instance(gamebgm);
    al_destroy_sample_instance(change);
}

bool GameWindow::mouse_hover(int startx, int starty, int width, int height)
{
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
}

void GameWindow::game_play()
{
    int msg;

    srand(time(NULL));

    msg = -1;
    game_reset();
    game_begin();

    while(msg != GAME_EXIT)
    {
        msg = game_run();
    }

    show_err_msg(msg);
};

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);

    if(timer == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font
    XLarge_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",60,0); //load extra large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    game_init();
}

void GameWindow::game_begin()
{
    // draw_running_map();

    //al_play_sample_instance(startSound);
    //while(al_get_sample_instance_playing(startSound));
    //al_play_sample_instance(backgroundSound);
    al_play_sample_instance(menubgm);

    al_start_timer(timer);
    flappyBird = new Bird;
    flappyBird->Load_move();
    flappyBoss = new Boss;
    flappyBoss->Load_move();
    std::cout << "Game Beginning...\n";
}

int GameWindow::game_run()
{
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {

        error = process_event();
    }
    return error;
}

void GameWindow::game_reset()
{
    mute = false;
    redraw = false;
    ground_pos_x = 0;
    
    // stop timer
    al_stop_timer(timer);
}

void GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

int GameWindow::game_update()
{
    bool isreachground = false;
    if (state != GAME_OVER && state != BIRD_FALL) update_ground_pos();
    if (state == IN_GAME) {
        isreachground = flappyBird->Move(state);
        if (isreachground) {
            change_state = true;
        }

        if(IMMORTAL == 0){
            // check whether collide with any pipe
            for(auto pipe: PIPEs){
                if(pipe->MultiPipe == 0){
                    if(flappyBird->isOverlap(pipe)){
                        change_state = true;
                        al_play_sample_instance(hitSound);
                    }
                }
                else{
                    if(flappyBird->isOverlap(pipe->GetLowerPipe()) || flappyBird->isOverlap(pipe->GetUpperPipe())){
                        change_state = true;
                        al_play_sample_instance(hitSound);
                    }
                }
            }

            // check whether collide with any weapon
            if(stage == 2){
                if(flappyBoss->WeaponCollide(flappyBird)){
                    change_state = true;
                    al_play_sample_instance(hitSound);
                }
            }
        }
        
        // Update every pipes, x = x - PIPE_dx
        for(int i=0 ; i<PIPEs.size() ; i++){
            Pipe* pipe = PIPEs[i];
            if(pipe->getX() < -PIPE_W){
                delete pipe;
                PIPEs.erase(PIPEs.begin() + i);
                i--;
            }
            else{
                pipe->UpdatePos(-PIPE_dx, 0);
            }
        }
        // Update every Bird pipes, when bird pass the pipe, score++
        for(int i=0 ; i<Bird_PIPEs.size() ; i++){
            Pipe* pipe = Bird_PIPEs[i];
            if(min(pipe->getRect()->points[0].x, pipe->getRect()->points[2].x) <= flappyBird->getCenterX()){
                score++;
                al_set_sample_instance_position(passSound, 0);
                al_play_sample_instance(passSound);
                delete pipe;
                Bird_PIPEs.erase(Bird_PIPEs.begin() + i);
                i--;
            }
            else if(pipe->getX() < -PIPE_W){
                delete pipe;
                Bird_PIPEs.erase(Bird_PIPEs.begin() + i);
                i--;
            }
            else{
                pipe->UpdatePos(-PIPE_dx, 0);
            }
        }

        if(stage == 2){
            flappyBoss->Move(PIPEs.back());
            flappyBoss->UpdateWeapons();
        }

        // update stage
        if(score >= Level_1_Score_Max && score < Level_2_Score_Max){
            stage = 1;
        }
        else if(score >= Level_2_Score_Max){
            stage = 2;
        }
    } else if(state == BIRD_FALL) {
        isreachground = flappyBird->Move(state);
        if (isreachground) {
            change_state = true;
        }
    } else if (state == MENU) {
        menutitle->Move();
        flappyBird->MoveInMenu(menutitle);
    } else if (state == GET_READY) {
        flappyBird->Move(state);
    }

    return GAME_CONTINUE;
}

void GameWindow::draw_running_map()
{
    al_clear_to_color(al_map_rgb(100, 100, 100));
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_scaled_bitmap(
        background,
        0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background),
        0, 0, window_width + 10, window_height + 10, 0
    );

    // Draw Pipes
    if(state == IN_GAME || state == GAME_OVER || state == BIRD_FALL) {
        for(auto pipe: PIPEs){
            pipe->Draw();
        }
    }

    // Draw Ground
    groundDraw();

    // Draw Bird
    if(state == IN_GAME || state == GAME_OVER || state == BIRD_FALL) {
        flappyBird->Draw();
    }

    // TODO: Draw Boss
    if(state == IN_GAME && stage == 2){
        // Draw Boss when in stage 2
        flappyBoss->Draw();
    }

    // Draw Buttoms and Titles
    if(state == MENU){
        startbuttom->Draw();
        menutitle->Draw();
        flappyBird->Draw();
    }
    else if (state == GET_READY) {
        ready->Draw();
        flappyBird->Draw();
    }
    else if(state == IN_GAME) {
        if(pause) resumebuttom->Draw();
        else pausebuttom->Draw();
        scoreDraw();
    }
    else if(state == GAME_OVER){
        okbuttom->Draw();
        endtitle->Draw();
        scoreboard->Draw();
    }

    al_flip_display();
}

void GameWindow::groundDraw()
{
    // Draw the 1st ground img
    al_draw_scaled_bitmap(
        ground, 0, 0, 
        al_get_bitmap_width(ground), al_get_bitmap_height(ground),
        ground_pos_x, ground_height, window_width, window_height - ground_height, 0
    );

    // Draw the 2nd gorund img
    int second_ground_pos = ground_pos_x - window_width;
    if (second_ground_pos <= -window_width) second_ground_pos += 2 * window_width;
    al_draw_scaled_bitmap(
        ground, 0, 0, 
        al_get_bitmap_width(ground), al_get_bitmap_height(ground),
        second_ground_pos, ground_height, window_width, window_height - ground_height, 0
    );
}

void GameWindow::scoreDraw()
{
    char buffer[20];
    sprintf(buffer, "%d", score);
    al_draw_text(XLarge_font, WHITE, window_width / 2, 50, ALLEGRO_ALIGN_CENTER, buffer);
}

void GameWindow::generate_new_pipes(){
    if(stage == 0){
        // stage 0: Random y position, fixed gap length
        if(FPS_count + 1 != (int)FPS) return;
        int center = randint(PIPE_CENTER_MIN, PIPE_CENTER_MAX);
        int velocity = 0;
        double radian = 0;
        PIPEs.emplace_back(new PairPipe(window_width + 100, center, radian, velocity));
        Bird_PIPEs.emplace_back(new PairPipe(window_width + 100, center, radian, velocity));
    }
    else{
        // stage 1: Random start y position, fixed gap length, but have velocity
        if(FPS_count + 1 != (int)FPS) return;
        int center = randint(PIPE_CENTER_MIN, PIPE_CENTER_MAX);
        int velocity = randint(PIPE_VELOCITY_MIN, PIPE_VELOCITY_MAX);
        double radian = 0;
        PIPEs.emplace_back(new PairPipe(window_width + 100, center, radian, velocity));
        Bird_PIPEs.emplace_back(new PairPipe(window_width + 100, center, radian, velocity));
    }
}

int GameWindow::process_event()
{
    int instruction = GAME_CONTINUE;

    al_wait_for_event(event_queue, &event);
    redraw = false;

    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(event.timer.source == timer) {
            redraw = true;
            if(state == IN_GAME){
                generate_new_pipes();

                // Update flappy boss
                if(stage == 2){
                    if(flappyBoss->GetPhase() == 1 && flappyBoss->isReachPipe()){
                        flappyBoss->Jump();
                    }

                    if(AttackCount >= RP){
                        flappyBoss->UpdatePhase(2);
                    }

                    if(flappyBoss->GetPhase() == 1 && FPS_count >= 0 && FPS_count < 3){
                        flappyBoss->Attack(flappyBird);
                        AttackCount++;
                    }
                }

                FPS_count = (FPS_count + 1 == (int)FPS) ? 0 : FPS_count + 1;
            }
        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_P:
                if(al_get_timer_started(timer) && state == IN_GAME) {
                    pause = true;
                    draw_running_map();
                    al_stop_timer(timer);
                }
                else if (state == IN_GAME) {
                    al_start_timer(timer);
                    pause = false;
                }
                break;
            case ALLEGRO_KEY_M:
                mute = !mute;
                if(mute)
                    al_stop_sample_instance((state == MENU ? menubgm : gamebgm));
                else
                    al_play_sample_instance((state == MENU ? menubgm : gamebgm));
                break;
            case ALLEGRO_KEY_SPACE:
                if (state == IN_GAME || state == GET_READY) {
                    flappyBird->ClickDetected();
                    if (state == GET_READY) change_state = true;
                }
                break;
        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if(event.mouse.button == 1) {
            if(startbuttom != NULL && state == MENU){
                selectedStart = startbuttom->mouse_hover(mouse_x, mouse_y);
            }
            if(state == GET_READY){
                flappyBird->ClickDetected();
                change_state = true;
            }
            if(pausebuttom != NULL && state == IN_GAME){
                selectedPause = pausebuttom->mouse_hover(mouse_x, mouse_y);
                if (!selectedPause) {
                    flappyBird->ClickDetected();
                }
            }
            if(resumebuttom != NULL && state == IN_GAME){
                selectedResume = resumebuttom->mouse_hover(mouse_x, mouse_y);
            }
            if(okbuttom != NULL && state == GAME_OVER){
                selectedOk = okbuttom->mouse_hover(mouse_x, mouse_y);
            }
            
            if(state == MENU){
                if(selectedStart){
                    change_state = true;
                }
            }
            else if(state == IN_GAME){
                if(selectedPause){
                    if(al_get_timer_started(timer)){
                        pause = true;
                        draw_running_map();
                        al_stop_timer(timer);
                    }
                    else{
                        al_start_timer(timer);
                        pause = false;
                    }
                }
            }
            else if(state == GAME_OVER){
                if(selectedOk){
                    change_state = true;
                }
            }
        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;

    }

    // Update Game state
    // MENU -> IN_GAME -> GAME_OVER
    if(change_state) {
        if (state == MENU) {
            state = GET_READY;
            FPS_count = 0;
            AttackCount = 0;
            PIPEs.clear();
            Bird_PIPEs.clear();
            flappyBird->Reset();

            // play game bgm
            al_stop_sample_instance(menubgm);
            while(al_get_sample_instance_playing(startbuttom->getSample()));
            al_set_sample_instance_position(gamebgm, 0);
            al_play_sample_instance(gamebgm);
        } else if (state == GET_READY) {
            state = IN_GAME;
        } else if (state == IN_GAME) {
            state = BIRD_FALL;
            
            // play the die sound
            al_set_sample_instance_position(dieSound, 0);
            al_play_sample_instance(dieSound);

            // update score
            if (best_score < score) best_score = score;
            scoreboard->Reset(score, best_score);
            score = 0;

        } else if (state == BIRD_FALL) {
            state = GAME_OVER;
        }
        else if (state == GAME_OVER) {
            state = MENU;
            stage = 0;

            // update pipes
            while(!PIPEs.empty()){
                delete PIPEs.back();
                PIPEs.pop_back();
            }
            while(!Bird_PIPEs.empty()){
                delete Bird_PIPEs.back();
                Bird_PIPEs.pop_back();
            }

            // play menu bgm
            al_stop_sample_instance(gamebgm);
            while (al_get_sample_instance_playing(okbuttom->getSample()));
            al_set_sample_instance_position(menubgm, 0);
            al_play_sample_instance(menubgm);
        }
        change_state = false;
    }

    if(redraw) {
        // update each object in game
        instruction = game_update();

        // Re-draw map
        draw_running_map();
        redraw = false;
    }

    return instruction;
}

