#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../GameCollision/GameCollision.h"
#include "../../BackGround/backGround.h"

class ScenePlay :public SceneBace
{
private:
	BackGround backGround;
	Player player;
	MapChip mapchip;

	int m_stage_clear_handle;
	int BGM;
	int m_gameover_handle;
	double m_handle_extend;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};