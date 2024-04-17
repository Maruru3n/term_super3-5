#include "../Common.h"

constexpr int PLAYER_COLLISION_SIZE = 80;

class Player {
protected:

	int handle;//�v���C���[�̉摜
	int sizeX;//�v���C���[��X�T�C�Y
	int sizeY;//�v���C���[��Y�T�C�Y

	float current_pos_x;//���݂�X���W
	float current_pos_y;//���݂�Y���W
	float pre_pos_X;//�O��X���W
	float pre_pos_Y;//�O��Y���W
	float movePowerX;//���̈ړ���
	float jumpPower;//�W�����v��

	bool jumpFlag;//�W�����v�t���O

public:
	
	void Init();

	void Step();

	void Draw();

};