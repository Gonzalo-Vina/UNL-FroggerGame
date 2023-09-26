#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>

using namespace std;

class SceneManager{
private:
	
		
public:
	static const int WIDTH=375, HEIGHT=140;
	static const int dW=10, dH=5;
	char plano[HEIGHT/dH][WIDTH/dW+1];
	
	void DrawChar(int A, int B, char c);
	void CreateBackground();
	void CreateLimits();
	void CleanScreen();
};
