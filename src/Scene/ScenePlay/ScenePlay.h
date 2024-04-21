#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../GameCollision/GameCollision.h"

class ScenePlay :public SceneBace
{
private:
	Player player;
	MapChip mapchip;

	int m_stage_clear_handle;
	int m_gameover_handle;
	double m_handle_extend;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};