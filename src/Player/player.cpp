#include "player.h"
#include "DxLib.h"
#include "../Input/Input.h"

void Player::Init() {

	handle = LoadGraph("Data/Image/Play/Player/Player.png");
	x = 0;
	y = 0;

	nextX = 200;
	nextY = 600;
	movePowerX = 0;

	jumpFlag = false;
	jumpPower = 0;
}


void Player::Step() {
	

	x = nextX;
	y = nextY;
		
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
		nextX += movePowerX;
		nextY -= jumpPower;
		jumpPower -= 0.5;
		if (jumpPower <= 0) {
			jumpPower = 0;
		}
	}
	nextY+=9;
	//一時的な当たり判定
	if (nextY >= 720-80) {
		jumpFlag = false;
		nextY = 720 - 80;
	}
	if (nextX >= 1280) {
		nextX = -80;
	}
}


void Player::Draw() {

	//デバック用
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
			DrawBox(x, y- 30, x + 50, y-5, GetColor(255, 0, 0), true);
			int Color = GetColor(0, 255, 0);
			if (jumpPower >= 50) { Color = GetColor(255, 255, 0); }
			DrawBox(x, y - 30, x + jumpPower, y-5, Color, true);
		}
	}
	DrawGraph(x,y,handle,true);

	DrawFormatString(0,0,GetColor(255,0,0),"%f",jumpPower);
}