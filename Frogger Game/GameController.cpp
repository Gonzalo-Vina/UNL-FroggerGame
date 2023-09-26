#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "GameController.h"

using namespace std;



void GameController::gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void GameController::StartGame(bool play){
	sceneManager.CreateBackground();
	
	while(play){
		sceneManager.CleanScreen();
		sceneManager.CreateLimits();
		sceneManager.DrawModel();
		
		gotoxy(0,0);
		puts(sceneManager.plano[0]);
	}
}
