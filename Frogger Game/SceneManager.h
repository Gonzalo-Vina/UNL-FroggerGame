class SceneManager{
private:
	const int WIDTH=600, HEIGHT=200;
	const int dW=10, dH=5;
	
	void DrawChar(char plano[HEIGHT/dH][WIDTH/dW+1], int A, int B, char c);
		
public:
	void CreatedBackground(char plano[HEIGHT/dH][WIDTH/dW+1]);
};
