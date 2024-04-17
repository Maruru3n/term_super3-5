#include "../Common.h"

constexpr int PLAYER_COLLISION_SIZE = 80;

class Player {
protected:

	int handle;//プレイヤーの画像
	int sizeX;//プレイヤーのXサイズ
	int sizeY;//プレイヤーのYサイズ

	float current_pos_x;//現在のX座標
	float current_pos_y;//現在のY座標
	float pre_pos_X;//前のX座標
	float pre_pos_Y;//前のY座標
	float movePowerX;//横の移動量
	float jumpPower;//ジャンプ力

	bool jumpFlag;//ジャンプフラグ

public:
	
	void Init();

	void Step();

	void Draw();

};