#include"iostream"
#include "gameapp.h"

using namespace std;

int main(int argc, char *argv[])
{

    cout << "Create gameApp" << endl;
    GameApp * game = new GameApp();
    cout << "Start gameApp" << endl;
    game->startGame();

    cout << "Finish gameApp" << endl;
    return 0;
}
