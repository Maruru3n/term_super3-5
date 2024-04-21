#include "DxLib.h"
#include "../../Common.h"
#include "SceneGameOver.h"
#include "../../Input/Input.h"

void SceneGameOver::Init()
{
	m_bg_handle = LoadGraph(GAMEOVER_BG_HANDLE_PATH);
	handle[0] = LoadGraph("Data/Image/GameOver/gameOver.png");
	handle[1] = LoadGraph("Data/Image/GameOver/gameOverUI.png");
	alpha = 0;
}
void SceneGameOver::Step()
{
	alpha++;
	if (alpha >= 255) {
		alpha = 255;
	}
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
		g_current_scene_ID = Title;
}
void SceneGameOver::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,alpha);
	DrawGraph(0, 0, handle[0], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	if (alpha >= 255) {
		DrawGraph(0, 0, handle[1], true);
	}
}
void SceneGameOver::Fin()
{

}