#include "../Common.h"


class Player {
protected:
	float x;//���݂�X���W
	float y;//���݂�Y���W
	float NextX;//����X���W
	float NextY;//����Y���W

	int sizeX;
	int sizeY;


public:
	
	void Init();

	void Step();

	void Draw();

};