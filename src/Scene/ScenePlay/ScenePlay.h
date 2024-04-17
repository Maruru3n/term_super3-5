#pragma once
#include "../SceneBace/SceneBace.h"
#include "../../Player/player.h"

class ScenePlay :public SceneBace
{
private:


public:

	Player player;

	void Init();
	void Step();
	void Draw();
	void Fin();
};