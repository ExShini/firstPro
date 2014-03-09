#include <iostream>
#include "gameapp.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

using namespace std;

int main()
{
    GameApp * app = new GameApp();
    app->startGame();
    return 0;
}
