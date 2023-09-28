#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>

using namespace std;

class Models{
private:
	
	char modelsASCII[12][2][8]{
		{
			"+Û+    ",
			"+ß+    "	
		},
	};
	
	struct coord{
		int x;
		int y;
	};
	
	struct dato{
		coord posModel[14];
		char model[14];
	};
	
public:
	int x, y, c, m;
	
	float vy = 0.0f;
	int dir = 0;
	
	dato pass[12];
	
	Models(int coordX, int coordY, int choiceModel, int m1){
		x = coordX;
		y = coordY;
		c = choiceModel;
		m = m1;
	}
	
	void ChooseModel();
	void Move(int &dir);
	void WaitBetweenMove();
	void SelectDirection(int &dir);
};
