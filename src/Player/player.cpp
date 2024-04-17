#include "player.h"
#include "DxLib.h"
#include "../Input/Input.h"

void Player::Init() {

	handle = LoadGraph("Data/Image/Play/Player/Player.png");
	current_pos_x = 200;
	current_pos_y = 600;

	pre_pos_X = 200;
	pre_pos_Y = 600;
	movePowerX = 0;

	jumpFlag = false;
	jumpPower = 0;
}


void Player::Step() {
	

	pre_pos_X = current_pos_x;
	pre_pos_Y = current_pos_y;
		
	//ジャンプ処理（ジャンプ力はためる）
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
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
		current_pos_x += movePowerX;
		current_pos_y -= jumpPower;
		jumpPower -= 0.5;
		if (jumpPower <= 0) {
			jumpPower = 0;
		}
	}
	current_pos_y +=9;
	//一時的な当たり判定
	if (current_pos_y >= 720-80) {
		jumpFlag = false;
		current_pos_y = 720 - 80;
	}
	if (current_pos_x >= 1280) {
		current_pos_x = -80;
	}
}


void Player::Draw() {

	//デバック用
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
			DrawBox(current_pos_x, current_pos_y- 30, current_pos_x + 50, current_pos_y-5, GetColor(255, 0, 0), true);
			int Color = GetColor(0, 255, 0);
			if (jumpPower >= 50) { Color = GetColor(255, 255, 0); }
			DrawBox(current_pos_x, current_pos_y - 30, current_pos_x + jumpPower, current_pos_y-5, Color, true);
		}
	}
	DrawGraph(current_pos_x, current_pos_y,handle,true);

	DrawFormatString(0,0,GetColor(255,0,0),"%f",jumpPower);
}