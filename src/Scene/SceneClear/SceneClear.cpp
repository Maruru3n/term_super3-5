#include "DxLib.h"
#include "../../Common.h"
#include "SceneClear.h"
#include "../../Input/Input.h"

void SceneClear::Init()
{
	m_bg_handle = LoadGraph(CLEAR_BG_HANDLE_PATH);
	SE = LoadSoundMem("Data/Sound/clear.bgm.mp3");
}
void SceneClear::Step()
{
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
		g_current_scene_ID = Title;
}
void SceneClear::Draw()
{
	DrawGraph(0, 0, m_bg_handle, true);
}
void SceneClear::Fin()
{

}