#include"iostream"
#include "gameapp.h"

using namespace std;

int main()
{

    cout << "Create gameApp" << endl;
    GameApp * game = new GameApp();
    cout << "iter gameApp" << endl;
    game->StartGame();

    cout << "Finish gameApp" << endl;
    return 0;
}
