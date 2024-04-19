#include "player.h"
#include "DxLib.h"
#include "../Input/Input.h"

void Player::Init() {

	LoadDivGraph("Data/Image/Play/Player/Player.png",3,1,3,80,80, handle);
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
}


void Player::Step() {
	
	//座標を更新
	pre_pos_x = current_pos_x;
	pre_pos_y = current_pos_y;

	//画面外に行ってもジャンプ処理を行うようにする
	if (current_pos_y < 0 ||
		current_pos_x < 0 ||
		current_pos_x > SCREEN_SIZE_X) {
		jumpFlag = true;
		moveXFlag = true;
	}
	//下に落ちたら元の場所に戻す
	if (current_pos_y > SCREEN_SIZE_Y) {
		ResetPos();
	}
		
	animIndex = 0;

	//ジャンプ処理（ジャンプ力はためる）
	if (!jumpFlag) {
		if (Input::IsKeyKeep(KEY_INPUT_SPACE)) {
			animIndex = 1;
			jumpPower += 0.5;
			if (jumpPower >= 50) {
				jumpPower = 50;
			}
		}
		if (Input::IsKeyRelease(KEY_INPUT_SPACE)) {
			jumpFlag = true;
			moveXFlag = true;
			movePowerX = PLAYER_DEFAULT_MOVE_POWER;
		}
	}

	Move();

	//一時的な当たり判定
	/*if (current_pos_y >= 720-80) {
		jumpFlag = false;
		current_pos_y = 720 - 80;
	}*/
	if (current_pos_x >= 1280) {
		current_pos_x = -PLAYER_COLLISION_SIZE;
	}
	if (current_pos_x < -PLAYER_COLLISION_SIZE) {
		current_pos_x = -PLAYER_COLLISION_SIZE;
	}
}

void Player::Move()
{
	//ジャンプ処理
	if (jumpFlag) {
		animIndex = 2;
		current_pos_y -= jumpPower;
		jumpPower -= 0.5;
		if (jumpPower <= 0) {
			jumpPower = 0;
		}
	}
	//横移動処理
	if (moveXFlag) {
		current_pos_x += movePowerX;
	}
	current_pos_y += 9;
}


void Player::Draw() {

	//チャージゲージ描画
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

	//プレイヤー描画
	//DrawGraph(current_pos_x, current_pos_y,handle[animIndex], true);
	
	DrawTurnGraph((int)current_pos_x, (int)current_pos_y, handle[animIndex],true);

	//ジャンプパワー描画
	DrawFormatString(0,0,GetColor(255,0,0),"%f",jumpPower);
	DrawFormatString(0,15,GetColor(255,0,0),"%f", movePowerX);
	DrawFormatString(0,30,GetColor(255,0,0),"%f,%f", current_pos_x, current_pos_y);
}

void Player::SetDefaultPos(float pos_x, float pos_y)
{
	default_pos_x = pos_x;
	default_pos_y = pos_y;
}
void Player::ResetPos()
{
	current_pos_x = default_pos_x;
	current_pos_y = default_pos_y;
}