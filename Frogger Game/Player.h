#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Models.h"
#include "Obstacles.h"

using namespace std;

class Player : public Models{
private:
	
	
public:
	Obstacles *obstacle = new Obstacles(0,0,0,0);
	
	dato colliderPlayer[1];
	
	Player(int coordX, int coordY, int choiceModel, int m1) : Models(coordX, coordY, choiceModel, m1){
		
	}
	void MoveController();
	
	int CheckCollision(int l, int OL[6], int NC[12]);
};
