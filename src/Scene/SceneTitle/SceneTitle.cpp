#include "DxLib.h"
#include "../../Common.h"
#include "SceneTitle.h"
#include "../../Input/Input.h"

void SceneTitle::Init()
{
	m_bg_handle = LoadGraph(TITLE_BG_HANDLE_PATH);
	BGM = LoadSoundMem("Data/Sound/title.mp3");
	ui_handle[0] = LoadGraph("Data/Image/Title/titleName.png");
	ui_handle[1] = LoadGraph("Data/Image/Title/titleUI.png");
	ui_size = 1.0;
	size_flag = false;
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
}
void SceneTitle::Step()
{
	//UIのサイズを変える処理
	if (!size_flag) {
		ui_size += 0.005f;
	}
	else {
		ui_size -= 0.005f;
	}
	if (ui_size < 1.0) {
		size_flag = false;
	}
	if (ui_size >1.2) {
		size_flag = true;
	}

	//エンターキーが押されるとシーンを移動
	if (Input::IsKeyPush(KEY_INPUT_RETURN))
		g_current_scene_ID = Play;
}
void SceneTitle::Draw()
{
	DrawRotaGraph(640, 360, 2,0.0,m_bg_handle, true);
	DrawRotaGraph(640, 360, 1.0, 0.0, ui_handle[0], true);
	DrawRotaGraph(640, 360, ui_size, 0.0, ui_handle[1], true);
}
void SceneTitle::Fin()
{
	StopSoundMem(BGM);
}