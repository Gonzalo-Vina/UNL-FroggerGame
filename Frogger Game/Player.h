#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Models.h"

using namespace std;

class Player : public Models{
private:
	
	
public:
	Player(int coordX, int coordY, int choiceModel, int m1) : Models(coordX, coordY, choiceModel, m1){
		
	}
	void MoveController();
};
