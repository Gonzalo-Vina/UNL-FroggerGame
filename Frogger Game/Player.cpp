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