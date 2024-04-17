#include "../Common.h"


class Player {
protected:
	float x;//現在のX座標
	float y;//現在のY座標
	float NextX;//次のX座標
	float NextY;//次のY座標

	int sizeX;//プレイヤーのXサイズ
	int sizeY;//プレイヤーのYサイズ


public:
	
	void Init();

	void Step();

	void Draw();

};