#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char GAMEOVER_BG_HANDLE_PATH[] = { "Data/Image/GameOver/bg_GameOver.png" };

class SceneGameOver :public SceneBace
{
private:
	int stage_index;

	int SE;
	int handle[2];
	int alpha;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};