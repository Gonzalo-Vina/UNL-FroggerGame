#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Models.h"

using namespace std;

class Obstacles : public Models{
private:
	
	
public:
	Obstacles(int coordX, int coordY, int choiceModel, int m1) : Models(coordX, coordY, choiceModel, m1){
		
	}
};
