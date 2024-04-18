#include "player.h"
#include "DxLib.h"
#include "../Input/Input.h"

void Player::Init() {

	LoadDivGraph("Data/Image/Play/Player/Player.png",3,1,3,80,80, handle);
	animIndex = 0;
	current_pos_x = 200;
	current_pos_y = 600;
	pre_pos_x = 200;
	pre_pos_y = 600;
	sizeX = 80;
	sizeY = 80;

	movePowerX = 0;

	jumpFlag = false;
	jumpPower = 0;
}


void Player::Step() {
	
	//���W���X�V
	pre_pos_x = current_pos_x;
	pre_pos_y = current_pos_y;
		
	animIndex = 0;

	//�W�����v�����i�W�����v�͂͂��߂�j
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
			animIndex = 1;
			movePowerX += 0.1;
			if (movePowerX >= 4) {
				movePowerX = 4;
			}
			jumpPower += 0.5;
			if (jumpPower >= 50) {
				jumpPower = 50;
			}
		}
		if (Input::IsKeyRelease(KEY_INPUT_SPACE)) {
			jumpFlag = true;
		}
	}
	if (jumpFlag) {
		animIndex = 2;
		current_pos_x += movePowerX;
		current_pos_y -= jumpPower;
		jumpPower -= 0.5;
		if (jumpPower <= 0) {
			jumpPower = 0;
		}
	}
	current_pos_y +=9;
	//�ꎞ�I�ȓ����蔻��
	if (current_pos_y >= 720-80) {
		jumpFlag = false;
		current_pos_y = 720 - 80;
	}
	if (current_pos_x >= 1280) {
		current_pos_x = -80;
	}
}


void Player::Draw() {

	//�`���[�W�Q�[�W�`��
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
			DrawBox(current_pos_x, current_pos_y- 30, current_pos_x + 50, current_pos_y-5, GetColor(255, 0, 0), true);
			int Color = GetColor(0, 255, 0);
			if (jumpPower >= 50) { Color = GetColor(255, 255, 0); }
			DrawBox(current_pos_x, current_pos_y - 30, current_pos_x + jumpPower, current_pos_y-5, Color, true);
		}
	}

	//�v���C���[�`��
	//DrawGraph(current_pos_x, current_pos_y,handle[animIndex], true);
	
	DrawTurnGraph(current_pos_x, current_pos_y, handle[animIndex],true);

	//�W�����v�p���[�`��
	DrawFormatString(0,0,GetColor(255,0,0),"%f",jumpPower);
}