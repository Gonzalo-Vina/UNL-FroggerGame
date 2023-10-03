#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Player.h"
#include "Obstacles.h"

using namespace std;

class SceneManager{
private:
	int vel1=0, vel2=0, vel3=0;
	
	int AL[9] = {0, 3, 6, 9, 12, 15, 18, 21, 24}; //Available Lines
	int NC[12] = {6,6,6,6,9,5,7,14,10,6,6,6}; //Numbers Characters
	int OL [6] = {3,3,4,3,2,3}; //Obstacles in Lines
	int PY [6] = {1,2,3,5,6,7}; //Position Y
	int PO [6] = {1,2,3,4,3,2};
	
	int SBO[4][4] = {{16,1,1,1}, //Space between obstacles
					 {6,20,1,1},
					 {3,14,24,1},
					 {2,13,17,26}}; 
		
public:
	static const int WIDTH=375, HEIGHT=140;
	static const int dW=10, dH=5;
	char plano[HEIGHT/dH][WIDTH/dW+1];
	
	Player* player = new Player(17,0,0,0);
	Obstacles* obstacle = new Obstacles(17,0,0,0);
	
	void DrawChar(int A, int B, char c);
	void CreateBackground();
	void CreateLimits();
	void CleanScreen();
	
	void DrawModel();
	void DrawObstacles(int t, int u, int c);
	void PositionObstacle();
	void PlaceObstacle();
	void SetSpeeds();
	void MoveObstacles();
	
	void CheckCollisions();
};
