// ColonyControlWin.cpp: определяет точку входа для консольного приложения.
//

#include"iostream"
#include "../gameapp.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Create gameApp" << endl;
    GameApp * game = new GameApp();
    cout << "Start gameApp" << endl;
    game->StartGame();

    cout << "Finish gameApp" << endl;
    return 0;
}

