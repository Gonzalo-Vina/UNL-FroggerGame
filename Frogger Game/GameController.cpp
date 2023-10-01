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

void GameController::ControlFPS(){
	finalT = clock();
	acumulador += float(finalT-inicioT)/CLOCKS_PER_SEC;
	inicioT = finalT;
	
	if(acumulador >= 0.2f) acumulador = 2.0f;
	
	while(acumulador>=dt){
		sceneManager.player->MoveController();
		
		acumulador -= dt;
	}
}

void GameController::StartGame(bool play){
	srand(static_cast <unsigned>(time(0)));
	
	sceneManager.CreateBackground();
	
	inicioT = clock();
	
	sceneManager.PositionObstacle();
	
	while(play){
		if(GetKeyState(VK_ESCAPE)&0x8000){
			play = false;
		}
		
		ControlFPS();
		
		sceneManager.CleanScreen();
		sceneManager.CreateLimits();
		sceneManager.PlaceObstacle();
		sceneManager.DrawModel();
		
		gotoxy(0,0);
		puts(sceneManager.plano[0]);
	}
}
