#include "DxLib.h"
#include "../../Common.h"
#include "SceneGameOver.h"
#include "../../Input/Input.h"
#include "../../MapChip/MapChip.h"

void SceneGameOver::Init()
{
	m_bg_handle = LoadGraph(GAMEOVER_BG_HANDLE_PATH);
	handle[0] = LoadGraph("Data/Image/GameOver/gameOver.png");
	handle[1] = LoadGraph("Data/Image/GameOver/gameOverUI.png");
	alpha = 0;
	SE = LoadSoundMem("Data/Sound/GameOver.bgm.mp3");

	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, "Data/Image/MapChip/SaveData.txt", "r");

	if (err != NULL)
		return;

	char stage_index_c;
	stage_index_c = fgetc(fp);

	stage_index = stage_index_c - '0';
	PlaySoundMem(SE, DX_PLAYTYPE_LOOP);
	fclose(fp);
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
		DrawFormatStringToHandle(600, 330, GetColor(255, 255, 255), font_handle, "%d Å^ %d", stage_index, STAGE_NUM);
	}
}
void SceneGameOver::Fin()
{
	StopSoundMem(SE);
}