#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Common.h"


void ScenePlay::Init()
{
	BGM = LoadSoundMem("Data/Sound/bgm_.mp3");
	m_stage_clear_handle = LoadGraph("Data/Image/Play/Clear.png");
	m_gameover_handle = LoadGraph("Data/Image/Play/GameOver.png");
	m_handle_extend = 0.0;

	backGround.Init();
	player.Init();
	mapchip.Init();

	for (int index_y = 0; index_y < MAPCHIP_NUM_Y; index_y++) {
		for (int index_x = 0; index_x < MAPCHIP_NUM_X; index_x++) {
			if (mapchip.GetMapData(index_y, index_x) == 1) {
				float player_default_pos_x = (float)(index_x * MAPCHIP_SIZE_X);
				float player_default_pos_y = (float)(index_y * MAPCHIP_SIZE_Y);

				player.SetDefaultPos(player_default_pos_x, player_default_pos_y);
				player.Reset();
				break;
			}
		}
	}
	ChangeVolumeSoundMem(255 * 80 / 100, BGM);
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP);
}


void ScenePlay::Step()
{
	backGround.Step();
	player.Step();
	CollisionMapPlayer(mapchip, player);

	//プレイヤーがゴールしたかどうか
	player.IsGoal();

	//ゴールした時の処理
	if (player.GetGoalFlag()) {
		m_handle_extend += 0.03;
		if (m_handle_extend >= 1.0)
			m_handle_extend = 1.0;

		//３秒数える
		int elapsed_time = 0;
		elapsed_time = GetNowCount() - g_count_time;
		if (elapsed_time >= 3000) {

			//最終ステージだったらクリアする
			if (mapchip.GetStageIndex() + 1 == STAGE_NUM)
				g_current_scene_ID = Clear;
			//次のステージに行く
			else {
				m_handle_extend = 0.0;

				player.SetGoalFlag(false);
				player.SetHP(PLAYER_DEFAULT_HP);
				mapchip.AddStageIndex();
				mapchip.LeadFile((char*)MAPCHIP_DATA_PATH[mapchip.GetStageIndex()]);

				for (int index_y = 0; index_y < MAPCHIP_NUM_Y; index_y++) {
					for (int index_x = 0; index_x < MAPCHIP_NUM_X; index_x++) {
						if (mapchip.GetMapData(index_y, index_x) == 1) {
							float player_default_pos_x = (float)(index_x * MAPCHIP_SIZE_X);
							float player_default_pos_y = (float)(index_y * MAPCHIP_SIZE_Y);

							player.SetDefaultPos(player_default_pos_x, player_default_pos_y);
							player.Reset();
							break;
						}
					}
				}
			}
		}
	}
	//残基が無くなった時の処理
	if (player.GetHP() == 0) {
		m_handle_extend += 0.03;
		if (m_handle_extend >= 1.0)
			m_handle_extend = 1.0;

		int elapsed_time = 0;
		elapsed_time = GetNowCount() - g_count_time;
		if (elapsed_time >= 3000)
			g_current_scene_ID = GameOver;


	}
}



void ScenePlay::Draw()
{
	
	backGround.Draw();
	mapchip.Draw();
	player.Draw();

	if (player.GetGoalFlag())
		DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2,
						m_handle_extend, 0.0,
						m_stage_clear_handle, true);
	else if (player.GetHP() == 0)
		DrawRotaGraph(SCREEN_SIZE_X / 2, SCREEN_SIZE_Y / 2,
						m_handle_extend, 0.0,
						m_gameover_handle, true);

	int font_width = GetDrawFormatStringWidthToHandle(font_handle, "%d ／ %d", mapchip.GetStageIndex(), STAGE_NUM);
	DrawFormatStringToHandle(SCREEN_SIZE_X - font_width, 0,
							GetColor(255, 255, 255), font_handle,
							"%d ／ %d", mapchip.GetStageIndex(), STAGE_NUM);
}


void ScenePlay::Fin()
{
	FILE* fp;
	errno_t err;
	StopSoundMem(BGM);
	err = fopen_s(&fp, "Data/Image/MapChip/SaveData.txt", "w");

	if (err != NULL)
		return;

	fprintf(fp, "%d", mapchip.GetStageIndex());


	fclose(fp);
	/*
	g_current_scene_ID = Clear;
	g_current_scene_ID = GameOver;
	*/
}