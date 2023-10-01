#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "SceneManager.h"

using namespace std;

void SceneManager::DrawChar(int A, int B, char c){
	B = HEIGHT/dH-1-B;
	if(A<0 || B<0 || A>=WIDTH/dW || B>=HEIGHT/dH) return;
	plano[B][A] = c;
}

void SceneManager::CreateBackground(){
	for(int i = 0; i<HEIGHT/dH; i++)
		plano[i][WIDTH/dW] = '\n';
	plano[HEIGHT/dH+1][WIDTH/dW] = '\0';
}

void SceneManager::CreateLimits(){
	for(int i=0; i<WIDTH/dW;i++){
		for(int j=0; j<HEIGHT/dH;j++){
			if(i==0 || i==(WIDTH/dW-1) || j==0 || j==(HEIGHT/dH-1)){
				DrawChar(i,j,'#');
			}
			if(j%3==0){
				DrawChar(i,j,'_');
			}
		}
	}
}

void SceneManager::CleanScreen(){
	for(int i=0; i<WIDTH/dW;i++){
		for(int j=0; j<HEIGHT/dH;j++){
			plano[j][i] = ' ';
		}
	}
}

void SceneManager::DrawModel(){
	player->ChooseModel();
	
	for(int i = 0; i < 6; i++){
		DrawChar(player->x+player->pass[player->c].posModel[i].x, 
				 AL[player->y]+player->pass[player->c].posModel[i].y, 
				 player->pass[player->c].model[i]);
	}
}
void SceneManager::DrawObstacles(int t, int u, int c){
	obstacle->ChooseModel();
	
	for(int j = 0; j < t; j++){
		for(int i = 0; i < NC[c]; i++){
			DrawChar((obstacle->car[u][j].x)+obstacle->pass[c].posModel[i].x, 
					(AL[obstacle->car[u][j].y])+obstacle->pass[c].posModel[i].y, 
					obstacle->pass[c].model[i]);
		}
	}
}
void SceneManager::PositionObstacle(){
	for(int j=0; j < 6; j++){
		for(int i = 0; i < OL[j]; i++){
			obstacle->car[j][i].x = rand()%6 + SBO[OL[j]-1][i];
			obstacle->car[j][i].y = PY[j];
		}
	}
}
void SceneManager::PlaceObstacle(){ 
	for(int i = 0; i < 6; i++){
		DrawObstacles(OL[i],i, PO[i]);
	}
}
