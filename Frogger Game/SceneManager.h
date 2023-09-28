#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Player.h"

using namespace std;

class SceneManager{
private:
	
	
	int AL[9] = {0, 3, 6, 9, 12, 15, 18, 21, 24}; //Available Lanes
		
public:
	static const int WIDTH=375, HEIGHT=140;
	static const int dW=10, dH=5;
	char plano[HEIGHT/dH][WIDTH/dW+1];
	
	Player* player = new Player(17,0,0,0);
	
	void DrawChar(int A, int B, char c);
	void CreateBackground();
	void CreateLimits();
	void CleanScreen();
	
	void DrawModel();
};
