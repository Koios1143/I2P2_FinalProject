#include "GameWindow.h"

GameWindow *FlappyBird;

int main(int argc, char *argv[])
{
    FlappyBird= new GameWindow();

    FlappyBird->game_play();

    delete FlappyBird;
    return 0;
}
