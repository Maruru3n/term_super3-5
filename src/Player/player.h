#include "../Common.h"


class Player {
protected:
	float x;//���݂�X���W
	float y;//���݂�Y���W
	float NextX;//����X���W
	float NextY;//����Y���W

	int sizeX;//�v���C���[��X�T�C�Y
	int sizeY;//�v���C���[��Y�T�C�Y


public:
	
	void Init();

	void Step();

	void Draw();

};