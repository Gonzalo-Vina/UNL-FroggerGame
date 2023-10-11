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
void GameController::UI_Controller(){
	gotoxy(55, 1); cout << "|-------------------------|";
	gotoxy(55, 2); cout << "|         FROGGER         |";
	gotoxy(55, 3); cout << "|-------------------------|";
	gotoxy(55, 4); cout << "|-------------------------|";
	gotoxy(55, 5); cout << "| Creado por Gonzalo Viña |";
	
	gotoxy(50, 9); cout << "  INSTRUCCIONES";
	gotoxy(50, 10); cout << "- Use las flechas del teclado para moverte";
	gotoxy(50, 11); cout << "- Evita chocar con los vehiculos.";
	gotoxy(50, 12); cout << "- Usa los troncos para llegar a las metas.";
	gotoxy(50, 13); cout << "- Consigue que 3 ranas lleguen al otro lado.";
	
	gotoxy(55, 16); cout << "Preciona ESC para salir";
	gotoxy(45, 20); cout << "Lifes: ";
	gotoxy(45, 21); cout << "Metas: ";
}
void GameController::WinOrLose(bool &continuePlaying){
	if(life==0){
		continuePlaying = false;
		gotoxy(55, 23); cout << "|  PERDISTE  |";
		gotoxy(55, 24); system("pause");
	}
	
	if(goals == 3){
		//GANASTE
	}
}
void GameController::UI_ScoresViewer(){
	gotoxy(52, 20); cout << life;
	gotoxy(52, 21); cout << goals;
}
void GameController::StartGame(bool play){
	srand(static_cast <unsigned>(time(0)));
	
	sceneManager.CreateBackground();
	
	inicioT = clock();
	
	sceneManager.PositionObstacle();
	sceneManager.PositionGoals();
	
	UI_Controller();
	
	while(play){
		if(GetKeyState(VK_ESCAPE)&0x8000){
			play = false;
		}
		
		ControlFPS();
		UI_ScoresViewer();
		
		WinOrLose(play);
		
		sceneManager.CleanScreen();
		sceneManager.CreateLimits();
		sceneManager.PlaceObstacle();
		sceneManager.PlaceGoals();
		sceneManager.DrawModel();
		sceneManager.MoveObstacles();
		sceneManager.CheckCollisions(life, goals);
		
		gotoxy(0,0);
		puts(sceneManager.plano[0]);
	}
}
