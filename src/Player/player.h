#include "../Common.h"

constexpr int PLAYER_COLLISION_SIZE = 80;

constexpr float PLAYER_DEFAULT_MOVE_POWER = 4.0f;
constexpr float PLAYER_SLOW_MOVE_POWER = 1.0f;

constexpr int PLAYER_DEFAULT_HP = 5;

class Player {
protected:

	int hp;

	int handle[3];//�v���C���[�̉摜
	int animIndex;//�A�j���[�V�����̓Y����

	float current_pos_x;//���݂�X���W
	float current_pos_y;//���݂�Y���W

	float pre_pos_x;//�O��X���W
	float pre_pos_y;//�O��Y���W

	float default_pos_x;//�ŏ���X���W
	float default_pos_y;//�ŏ���Y���W

	float movePowerX;//���̈ړ���
	float jumpPower;//�W�����v��

	bool jumpFlag;//�W�����v�t���O
	bool moveXFlag;//���ړ��t���O

	bool goalFlag;

public:
	
	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`�揈��
	void Draw();

	void Move();

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

	//�v���C���[�̍ŏ��̍��W
	void SetDefaultPos(float pos_x, float pos_y);
	void Reset();

	//���̓����蔻����Ƃ����Ƃ��ɌĂ�ł����Ƃ��ꂵ��
	void SetJumpFlag(bool flag = false) { jumpFlag = flag; }
	void SetMoveFlag(bool flag = false) { moveXFlag = flag; }

	//�v���C���[�̉������ɓ�����
	float GetMovePowerX() { return movePowerX; }
	void SetMovePowerX(float power) { movePowerX = power; }

	void SetGoalFlag(bool flag = true) { goalFlag = flag; }
};