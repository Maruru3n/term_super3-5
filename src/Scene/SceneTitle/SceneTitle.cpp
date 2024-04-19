#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"

void SceneTitle::Init()
{
	m_bg_handle = LoadGraph(TITLE_BG_HANDLE_PATH);
}
void SceneTitle::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
		g_current_scene_ID = Play;
}
void SceneTitle::Draw()
{
	DrawGraph(0, 0, m_bg_handle, true);
}
void SceneTitle::Fin()
{

}