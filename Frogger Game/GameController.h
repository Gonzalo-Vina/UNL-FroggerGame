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
	
	float fps = 24.0f;
	float dt = 1.0f/fps;
	float acumulador = 0.0f;
	
	clock_t inicioT;
	clock_t finalT;
	
public:
	bool isPlay = true;
	
	void gotoxy(int x, int y);
	void ControlFPS();
	void StartGame(bool play);
};
