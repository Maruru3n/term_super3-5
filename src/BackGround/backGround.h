#pragma once
#include "DxLib.h"


class BackGround {
private:
	int handle[2];
	float sun_pos_x;
	float sun_pos_y;
	float moon_pos_x;
	float moon_pos_y;
	float radian;
	float radius;
	int timeFlag;
	int red;
	int green;
	int blue;


public:
	void Init();

	void Step();

	void Draw();

};
