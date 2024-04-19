#include "DxLib.h"
#include "../../Common.h"
#include "SceneGameOver.h"
#include "../../Input/Input.h"

void SceneGameOver::Init()
{
	m_bg_handle = LoadGraph(GAMEOVER_BG_HANDLE_PATH);
}
void SceneGameOver::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
		g_current_scene_ID = Title;
}
void SceneGameOver::Draw()
{
	DrawGraph(0, 0, m_bg_handle, true);
}
void SceneGameOver::Fin()
{

}