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
	//残りの体力を更新
	pre_hp = hp;
	//座標を更新
	pre_pos_x = current_pos_x;
	pre_pos_y = current_pos_y;
	//フラグを更新
	pre_goalFlag = goalFlag;

	//画面外に行ってもジャンプ処理を行うようにする
	if (current_pos_y < 0 ||
		current_pos_x < 0 ||
		current_pos_x > SCREEN_SIZE_X) {
		jumpFlag = true;
		moveXFlag = true;
	}
	//下に落ちたら元の場所に戻す
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

	//ゴールしていないなら行う処理
	if (!goalFlag) {
		//ジャンプ処理（ジャンプ力はためる）
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

	//一時的な当たり判定
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

	//ジャンプ処理
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
	//横移動処理
	if (moveXFlag) {
		current_pos_x += movePowerX;
	}
	current_pos_y += gravity_power;
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
	DrawTurnGraph((int)current_pos_x, (int)current_pos_y, handle[animIndex],true);

	//ｈｐ描画
	for (int index = 0;index < hp;index++) {
		DrawGraph(0 + 34 * index, 2, hpHandle, true);
	}

	//ジャンプパワー描画
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