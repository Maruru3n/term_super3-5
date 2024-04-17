#pragma once

#include "SceneBace/SceneBace.h"

enum SceneID
{
	Title,
	Play,
	GameOver,
	Clear,

	LOOP
};

class SceneManager
{
private:
	SceneBace* scene;

public:
	void Main();
};