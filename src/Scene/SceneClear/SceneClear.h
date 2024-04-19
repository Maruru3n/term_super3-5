#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char CLEAR_BG_HANDLE_PATH[] = { "Data/Image/Clear/Clear.png" };

class SceneClear :public SceneBace
{
private:

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};