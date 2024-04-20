#pragma once
#include "../SceneBace/SceneBace.h"

constexpr char TITLE_BG_HANDLE_PATH[] = { "Data/Image/Title/title.png" };


class SceneTitle :public SceneBace
{
private:
	int ui_handle[2];
	float ui_size;
	bool size_flag;
public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};