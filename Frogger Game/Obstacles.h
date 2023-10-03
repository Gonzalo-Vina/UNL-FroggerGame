#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Models.h"
#pragma once

using namespace std;

class Obstacles : public Models{
private:

	
public:
	dato colliderObstacles[12][5];
	
	Obstacles(int coordX, int coordY, int choiceModel, int m1) : Models(coordX, coordY, choiceModel, m1){
		
	}
};
