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
		
		player->colliderPlayer[0].posModel[i].x = (player->x+player->pass[player->c].posModel[i].x);
		player->colliderPlayer[0].posModel[i].y = (AL[player->y]+player->pass[player->c].posModel[i].y);
	}
}
void SceneManager::DrawObstacles(int t, int u, int c){
	obstacle->ChooseModel();
	
	for(int j = 0; j < t; j++){
		for(int i = 0; i < NC[c]; i++){
			DrawChar((obstacle->car[u][j].x)+obstacle->pass[c].posModel[i].x, 
					(AL[obstacle->car[u][j].y])+obstacle->pass[c].posModel[i].y, 
					obstacle->pass[c].model[i]);
			
			player->obstacle->colliderObstacles[u][j].posModel[i].x = ((obstacle->car[u][j].x)+obstacle->pass[c].posModel[i].x);
			player->obstacle->colliderObstacles[u][j].posModel[i].y = ((AL[obstacle->car[u][j].y])+obstacle->pass[c].posModel[i].y);
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
void SceneManager::PositionGoals(){
	for(int i = 0; i < 3; i++){
		obstacle->car[10][i].y = 8;
		obstacle->car[10][i].x = GM[i];
	}
}
void SceneManager::PlaceGoals(){
	DrawObstacles(3, 10, 11);
}
void SceneManager::SetSpeeds(){
	vel1++;
	if(vel1>500)
		vel1=0;
	
	vel2++;
	if(vel2>450)
		vel2=0;
	
	vel3++;
	if(vel3>400)
		vel3=0;
}
void SceneManager::MoveObstacles(){
	SetSpeeds();
	
	if(vel1 == 0){
		for(int i = 0; i < OL[0]; i++){
			obstacle->car[0][i].x++;
			if(obstacle->car[0][i].x > 34)
				obstacle->car[0][i].x = 0;
		}
		for(int i = 0; i < OL[3]; i++){
			obstacle->car[3][i].x--;
			if(obstacle->car[3][i].x < 0)
				obstacle->car[3][i].x = 34;
		}
	}
	
	if(vel2 == 0){
		for(int i = 0; i < OL[2]; i++){
			obstacle->car[2][i].x++;
			if(obstacle->car[2][i].x > 34)
				obstacle->car[2][i].x = 0;
		}
		for(int i = 0; i < OL[5]; i++){
			obstacle->car[5][i].x--;
			if(obstacle->car[5][i].x < 0)
				obstacle->car[5][i].x = 34;
		}
	}
	
	if(vel3 == 0){
		for(int i = 0; i < OL[1]; i++){
			obstacle->car[1][i].x--;
			if(obstacle->car[1][i].x < 0)
				obstacle->car[1][i].x = 34;
		}
		for(int i = 0; i < OL[4]; i++){
			obstacle->car[4][i].x++;
			if(obstacle->car[4][i].x > 34)
				obstacle->car[4][i].x = 0;
		}
	}
}
void SceneManager::CheckCollisions(int &life, int &goal){
	switch(player->y){
	case 0:
		break;
	case 1:
		if(player->CheckCollision(player->y, OL, NC, obstacle) == 1){
			player->ResetPosition();
			life--;
		}
		break;
	case 2:
		if(player->CheckCollision(player->y, OL, NC, obstacle) == 1){
			player->ResetPosition();
			life--;
		}
		
		break;
	case 3:
		if(player->CheckCollision(player->y, OL, NC, obstacle) == 1){
			player->ResetPosition();
			life--;
		}
		
		break;
	case 5:
		if(player->CheckCollision(player->y-1, OL, NC, obstacle) == 1){
			player->MoveWithTrunks(1, obstacle);
		} else{
			player->ResetPosition();
			life--;
		}
		break;
	case 6:
		if(player->CheckCollision(player->y-1, OL, NC, obstacle) == 1){
			player->MoveWithTrunks(0, obstacle);
		} else{
			player->ResetPosition();
			life--;
		}
		break;
	case 7:
		if(player->CheckCollision(player->y-1, OL, NC, obstacle) == 1){
			player->MoveWithTrunks(1, obstacle);
		} else{
			player->ResetPosition();
			life--;
		}
		break;
	case 8:
		if(player->CheckCollisionWithGoal(OL, NC, obstacle) == 1){
			player->ResetPosition();
			goal++;
		} else{
			player->ResetPosition();
			life--;
		}
		break;
	}
}
