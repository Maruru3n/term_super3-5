#pragma once
#include <string>

using namespace std;

#define	SCREEN_SIZE_X	1280	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720		// Y方向の画面サイズを指定

void InitGame();
void FinGame();

extern int g_current_scene_ID;
enum SceneID
{
	Title,
	Play,
	GameOver,
	Clear,

	LOOP
};