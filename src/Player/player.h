#include "../Common.h"


class Player {
protected:

	int handle;//�v���C���[�̉摜
	int sizeX;//�v���C���[��X�T�C�Y
	int sizeY;//�v���C���[��Y�T�C�Y

	float x;//���݂�X���W
	float y;//���݂�Y���W
	float nextX;//����X���W
	float nextY;//����Y���W
	float jumpPower;//�W�����v��

	bool jumpFlag;//�W�����v�t���O

public:
	
	void Init();

	void Step();

	void Draw();

};