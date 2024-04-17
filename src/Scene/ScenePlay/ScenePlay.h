#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../Player/player.h"
#include "../../MapChip/MapChip.h"

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