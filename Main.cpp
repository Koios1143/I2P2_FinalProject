#include "./GameWindow.h"

int main(int argc, char *argv[])
{
    GameWindow *FlappyBird= new GameWindow();

    FlappyBird->game_play();

    delete FlappyBird;
    return 0;
}
