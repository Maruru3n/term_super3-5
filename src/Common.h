#pragma once
#include <string>

using namespace std;

#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720		// Y�����̉�ʃT�C�Y���w��

void InitGame();
void FinGame();

extern int g_current_scene_ID;
extern int g_count_time;
extern int font_handle;

enum SceneID
{
	Title,
	Play,
	GameOver,
	Clear,

	LOOP
};