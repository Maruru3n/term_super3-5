#include "player.h"
#include "DxLib.h"
#include "../Input/Input.h"

void Player::Init() {

	hp = PLAYER_DEFAULT_HP;
	pre_hp = hp;

	LoadDivGraph("Data/Image/Play/Player/Player.png",3,1,3,80,80, handle);
	hpHandle = LoadGraph("Data/Image/Play/Player/hp.png");
	soundHandle[0]= LoadSoundMem("Data/Sound/jump1.mp3");
	soundHandle[1] = LoadSoundMem("Data/Sound/jump2.mp3");
	
	animIndex = 0;
	default_pos_x = 0;
	default_pos_y = 0;
	current_pos_x = 0;
	current_pos_y = 0;
	pre_pos_x = 0;
	pre_pos_y = 0;

	movePowerX = PLAYER_DEFAULT_MOVE_POWER;
	jumpPower = 0;

	jumpFlag = false;
	moveXFlag = false;

	goalFlag = false;
	pre_goalFlag = goalFlag;
	
}


void Player::Step() {
	//�c��̗̑͂��X�V
	pre_hp = hp;
	//���W���X�V
	pre_pos_x = current_pos_x;
	pre_pos_y = current_pos_y;
	//�t���O���X�V
	pre_goalFlag = goalFlag;

	//��ʊO�ɍs���Ă��W�����v�������s���悤�ɂ���
	if (current_pos_y < 0 ||
		current_pos_x < 0 ||
		current_pos_x > SCREEN_SIZE_X) {
		jumpFlag = true;
		moveXFlag = true;
	}
	//���ɗ������猳�̏ꏊ�ɖ߂�
	if (current_pos_y > SCREEN_SIZE_Y) {
		hp--;
		if (hp <= 0) {
			if(pre_hp==1)
				g_count_time = GetNowCount();
			hp = 0;
			current_pos_y = SCREEN_SIZE_Y;
			StopSoundMem(soundHandle[0]);
		}
		else
			ResetPos();
	}
		
	animIndex = 0;

	//�S�[�����Ă��Ȃ��Ȃ�s������
	if (!goalFlag) {
		//�W�����v�����i�W�����v�͂͂��߂�j
		if (!jumpFlag) {
			if (Input::IsKeyPush(KEY_INPUT_SPACE)) {
				PlaySoundMem(soundHandle[0], DX_PLAYTYPE_BACK);
			}
			if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
				animIndex = 1;
				jumpPower += 0.5;
				if (jumpPower >= 50) {
					jumpPower = 50;
				}
			}
			if (Input::IsKeyRelease(KEY_INPUT_SPACE)) {
				PlaySoundMem(soundHandle[1], DX_PLAYTYPE_BACK);
				jumpFlag = true;
				moveXFlag = true;
				movePowerX = PLAYER_DEFAULT_MOVE_POWER;
			}
		}

		Move();
	}

	//�ꎞ�I�ȓ����蔻��
	if (current_pos_x >= 1280) {
		current_pos_x = -PLAYER_COLLISION_SIZE;
	}
	if (current_pos_x < -PLAYER_COLLISION_SIZE) {
		current_pos_x = -PLAYER_COLLISION_SIZE;
	}
}

void Player::Move()
{
	int gravity_power = 9;

	//�W�����v����
	if (jumpFlag) {
		animIndex = 2;
		current_pos_y -= jumpPower;
		jumpPower -= 0.5;
		if (jumpPower <= 0) {
			jumpPower = 0;
		}
	}
	else
		gravity_power = 1;
	//���ړ�����
	if (moveXFlag) {
		current_pos_x += movePowerX;
	}
	current_pos_y += gravity_power;
}


void Player::Draw() {

	//�`���[�W�Q�[�W�`��
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
			DrawBox((int)current_pos_x,
				(int)(current_pos_y - 30),
				(int)(current_pos_x + 50),
				(int)(current_pos_y - 5),
				GetColor(255, 0, 0), true);

			int Color = GetColor(0, 255, 0);

			if (jumpPower >= 50) { Color = GetColor(255, 255, 0); }

			DrawBox((int)current_pos_x,
				(int)(current_pos_y - 30),
				(int)(current_pos_x + jumpPower),
				(int)(current_pos_y - 5),
				Color, true);
		}
	}

	//�v���C���[�`��
	DrawTurnGraph((int)current_pos_x, (int)current_pos_y, handle[animIndex],true);

	//�����`��
	for (int index = 0;index < hp;index++) {
		DrawGraph(0 + 34 * index, 2, hpHandle, true);
	}

	//�W�����v�p���[�`��
	//DrawFormatString(0,0,GetColor(255,0,0),"%d",hp);
}

void Player::SetDefaultPos(float pos_x, float pos_y)
{
	default_pos_x = pos_x;
	default_pos_y = pos_y;
}
void Player::Reset()
{
	hp = PLAYER_DEFAULT_HP;
	goalFlag = false;

	ResetPos();
}
void Player::ResetPos()
{
	current_pos_x = default_pos_x;
	current_pos_y = default_pos_y;
}

void Player::IsGoal()
{
	if (!pre_goalFlag && goalFlag) {
		g_count_time = GetNowCount();
	}
}