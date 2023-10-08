#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Models.h"

using namespace std;

void Models::ChooseModel(){
	for(int t=0; t<12; t++){
		int q=0;
		int y;
		for(int i=0; i<2; i++){
			y = 2-i;
			for(int j=0; j<7; j++){
				if(modelsASCII[t][i][j] != ' '){
					pass[t].posModel[q] = {j,y};
					pass[t].model[q] = modelsASCII[t][i][j];
					q++;
				}
			}
		}
	}
}
void Models::Move(int &dir){
	vy -= 1150.0f * 0.0416;
	if(vy >= 752.0f)
		SelectDirection(dir);
}
void Models::WaitBetweenMove(){
	if(vy <= 600.0f){
		vy = 800.0f;
	}
}
void Models::SelectDirection(int &dir){
	switch(dir){
	case 1: 
		y++;
		dir = 0;
		ac=1;
		break;
	case 2:
		x += 2;
		dir = 0;
		break;
	case 3:
		y--;
		dir = 0;
		ac=1;
		break;
	case 4:
		x -= 2;
		dir = 0;
		break;
	}
}
