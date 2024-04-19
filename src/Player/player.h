#include "../Common.h"

constexpr int PLAYER_COLLISION_SIZE = 80;

class Player {
protected:

	int handle[3];//�v���C���[�̉摜
	int animIndex;//�A�j���[�V�����̓Y����
	int sizeX;//�v���C���[��X�T�C�Y
	int sizeY;//�v���C���[��Y�T�C�Y

	float current_pos_x;//���݂�X���W
	float current_pos_y;//���݂�Y���W

	float pre_pos_x;//�O��X���W
	float pre_pos_y;//�O��Y���W

	float default_pos_x;//�ŏ���X���W
	float default_pos_y;//�ŏ���Y���W

	float movePowerX;//���̈ړ���
	float jumpPower;//�W�����v��

	bool jumpFlag;//�W�����v�t���O

public:
	
	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	//�O�t���[����X���W�𓾂�
	float GetPrePosX() { return pre_pos_x; }

	//�O�t���[����Y���W�𓾂�
	float GetPrePosY() { return pre_pos_y; }

	//���݂�X���W�𓾂�
	float GetCurrentPosX() { return current_pos_x; }

	//���݂�Y���W�𓾂�
	float GetCurrentPosY() { return current_pos_y; }

	//�v���C���[X���W���Z�b�g
	void SetCurrentPosX(float pos_x) { current_pos_x = pos_x; }

	//�v���C���[Y���W���Z�b�g
	void SetCurrentPosY(float pos_y) { current_pos_y = pos_y; }

	void SetDefaultPos(float pos_x, float pos_y);
	void ResetPos();

	//�v���C���[��X�T�C�Y
	int GetSizeX() { return sizeX; }

	//�v���C���[��Y�T�C�Y
	int GetSizeY() { return sizeY; }

	//���̓����蔻����Ƃ����Ƃ��ɌĂ�ł����Ƃ��ꂵ��
	void SetJump() { jumpFlag = false; }
};