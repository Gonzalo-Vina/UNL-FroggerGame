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
	
	int life = 5;
	int goals = 0;
	
public:
	bool isPlay = true;
	
	void gotoxy(int x, int y);
	void ControlFPS();
	void UI_Controller();
	void UI_ScoresViewer();
	void WinOrLose(bool &continuePlaying);
	void StartGame(bool play);
};
