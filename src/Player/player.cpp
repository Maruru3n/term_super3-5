#include "player.h"
#include "DxLib.h"
#include "../Input/Input.h"

void Player::Init() {

	handle = LoadGraph("Data/Image/Play/Player/Player.png");
	x = 0;
	y = 0;

	nextX = 200;
	nextY = 600;

	jumpFlag = false;
	jumpPower = 0;
}


void Player::Step() {
	
		
	x = nextX;
	y = nextY;
		
	//ジャンプ処理（ジャンプ力はためる）
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {

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
}


void Player::Draw() {


	DrawGraph(x,y,handle,true);

	DrawFormatString(0,0,GetColor(255,0,0),"%f",jumpPower);
}