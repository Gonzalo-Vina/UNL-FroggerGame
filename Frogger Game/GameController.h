#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "SceneManager.h"

using namespace std;

class GameController{
private:
	SceneManager sceneManager;
	
public:
	bool isPlay = true;
	
	void gotoxy(int x, int y);
	void StartGame(bool play);
};
