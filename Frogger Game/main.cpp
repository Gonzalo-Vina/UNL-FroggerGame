#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "GameController.h"

using namespace std;

GameController gameController;

int main (int argc, char *argv[]) {
	gameController.StartGame(gameController.isPlay);
		
	return 0;
}

