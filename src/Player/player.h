#include "../Common.h"


class Player {
protected:

	int handle;//プレイヤーの画像
	int sizeX;//プレイヤーのXサイズ
	int sizeY;//プレイヤーのYサイズ

	float x;//現在のX座標
	float y;//現在のY座標
	float nextX;//次のX座標
	float nextY;//次のY座標
	float jumpPower;//ジャンプ力

	bool jumpFlag;//ジャンプフラグ

public:
	
	void Init();

	void Step();

	void Draw();

};