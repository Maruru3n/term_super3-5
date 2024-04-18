#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../GameCollision/GameCollision.h"

class ScenePlay :public SceneBace
{
private:
	Player player;
	MapChip mapchip;

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};