#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char TITLE_BG_HANDLE_PATH[] = { "Data/Image/Title/bg_title.png" };

class SceneTitle :public SceneBace
{
private:

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};