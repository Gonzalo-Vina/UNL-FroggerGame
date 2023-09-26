void SceneManager::DrawChar(char plano[HEIGHT/dH][WIDTH/dW+1], int A, int B, char c){
	B = HEIGHT/dH-1-B;
	if(A<0 || B<0 || A>=WIDTH/dW || B>=HEIGHT/dH) return;
	plano[B][A] = c;
}

void SceneManager::CreatedBackground(char plano[HEIGHT/dH][WIDTH/dW+1]){
	for(int i=0; i<WIDTH/dW;i++){
		for(int j=0; j<HEIGHT/dH;j++){
			if(i==0 || i==59 || j==0 || j==39){
				DrawChar(plano,i,j,´#´);
			}
			if(j%3==0){
				DrawChar(plano,i,j,´_´);
			}
		}
	}
}
