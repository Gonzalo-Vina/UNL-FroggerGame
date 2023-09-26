#include <iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
#include <conio2.h>
#include "Models.h"

using namespace std;

void Models::ChooseModel(){
	for(int t=0; t<1; t++){
		int q=0;
		int y;
		for(int i=0; i<2; i++){
			y = 2-i;
			for(int j=0; j<7; j++){
				if(modelsASCII[t][i][j] != ' '){
					pass[t].posModel[q] = {j,y};
					pass[t].model[q] = modelsASCII[t][i][j];
					q++;
				}
			}
		}
	}
}
