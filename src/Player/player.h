#include "../Common.h"

constexpr int PLAYER_COLLISION_SIZE = 80;

class Player {
protected:

	int handle[3];//プレイヤーの画像
	int animIndex;//アニメーションの添え字
	int sizeX;//プレイヤーのXサイズ
	int sizeY;//プレイヤーのYサイズ

	float current_pos_x;//現在のX座標
	float current_pos_y;//現在のY座標

	float pre_pos_x;//前のX座標
	float pre_pos_y;//前のY座標

	float default_pos_x;//最初のX座標
	float default_pos_y;//最初のY座標

	float movePowerX;//横の移動量
	float jumpPower;//ジャンプ力

	bool jumpFlag;//ジャンプフラグ

public:
	
	//初期化
	void Init();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//前フレームのX座標を得る
	float GetPrePosX() { return pre_pos_x; }

	//前フレームのY座標を得る
	float GetPrePosY() { return pre_pos_y; }

	//現在のX座標を得る
	float GetCurrentPosX() { return current_pos_x; }

	//現在のY座標を得る
	float GetCurrentPosY() { return current_pos_y; }

	//プレイヤーX座標をセット
	void SetCurrentPosX(float pos_x) { current_pos_x = pos_x; }

	//プレイヤーY座標をセット
	void SetCurrentPosY(float pos_y) { current_pos_y = pos_y; }

	void SetDefaultPos(float pos_x, float pos_y);
	void ResetPos();

	//プレイヤーのXサイズ
	int GetSizeX() { return sizeX; }

	//プレイヤーのYサイズ
	int GetSizeY() { return sizeY; }

	//床の当たり判定をとったときに呼んでくれるとうれしい
	void SetJump() { jumpFlag = false; }
};