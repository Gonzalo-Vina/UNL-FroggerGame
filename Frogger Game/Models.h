#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#pragma once

using namespace std;

class Models{
private:
	
	char modelsASCII[12][2][8]{
		{
			"+л+    ",
			"+п+    "	
		},
		{
			"мллм   ",
			"Љ  Љ   "
		},
		{
			"мллл   ",
			"Љ  Љ   "	
		},
		{
			"млмм   ",
			"Љ  Љ   "
		},
		{
			"млмллл ",
			"Љ  Љ Љ "
		},
		{
			"<м     ",
			"  пмп  "	
		},
		{
			">ммм_  ",
			" + +   "
		},
		{
			"ллллллл",
			"ллллллл"
		},
		{
			"ллллл  ",
			"ллллл  "
		},
		{
			"ллл    ",
			"ллл    "
		},
		{
			"ммм    ",
			"ппп    "
		},
		{
			"ллл    ",
			"ллл    "
		},
	};
	
	struct coord{
		int x;
		int y;
	};
	
	
	
public:
	struct dato{
		coord posModel[14];
		char model[14];
	};
	
	int x, y, c, m;
	
	float vy = 0.0f;
	int dir = 0;
	
	int ac=0;
	
	dato pass[12];
	coord car[12][5];
	
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
