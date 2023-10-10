#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Player.h"

using namespace std;

void Player::MoveController(){
	if(GetKeyState(VK_UP)&0x8000 && y < 8){
		this->WaitBetweenMove();
		dir = 1;
	}
	if(GetKeyState(VK_DOWN)&0x8000 && y > 0){
		this->WaitBetweenMove();
		dir = 3;
	}
	if(GetKeyState(VK_RIGHT)&0x8000 && x < 32){
		this->WaitBetweenMove();
		dir = 2;
	}
	if(GetKeyState(VK_LEFT)&0x8000 && x > 1){
		this->WaitBetweenMove();
		dir = 4;
	}
	
	this->Move(this->dir);
}
int Player::CheckCollision(int l, int OL[6], int NC[12], Obstacles *positionObstacles){
	for(int t=0; t<OL[l-1];t++){
		for(int i=0; i<NC[0]; i++){
			for(int j=0; j<NC[l]; j++){
				if(colliderPlayer[0].posModel[i].x == obstacle->colliderObstacles[l-1][t].posModel[j].x &&
					colliderPlayer[0].posModel[i].y == obstacle->colliderObstacles[l-1][t].posModel[j].y)
				{
					if(ac==1 && this->y>4){
						gu1 = positionObstacles->car[l-1][t].x;
						gu2 = l-1;
						gu3 = t;
						ac = 0;
					}
					
					return 1;
				}
			}
		}
	}	
}
int Player::CheckCollisionWithGoal(int OL[6], int NC[12], Obstacles *positionObstacles){
	for(int t=0; t<3;t++){
		for(int i=0; i<NC[0]; i++){
			for(int j=0; j<NC[9]; j++){
				if(colliderPlayer[0].posModel[i].x == obstacle->colliderObstacles[10][t].posModel[j].x &&
					colliderPlayer[0].posModel[i].y == obstacle->colliderObstacles[10][t].posModel[j].y)
				{
					return 1;
				}
			}
		}
	}
}
void Player::MoveWithTrunks(int l, Obstacles *positionObstacles){
	if(vy <= 600){
		switch(l){
		case 0:
			if(gu1 < positionObstacles->car[gu2][gu3].x){
				do{
					if(this->x < 34) { this->x ++; }
					gu1++;
					
				} while(gu1 == positionObstacles->car[gu2][gu3].x);
			}
			
			break;
		case 1:
			if(gu1 > positionObstacles->car[gu2][gu3].x){
				do{
					if(this->x > 0) { this->x --; }
					gu1--;
					
				} while(gu1 == positionObstacles->car[gu2][gu3].x);
			}
			
			break;
		}
	}
}
