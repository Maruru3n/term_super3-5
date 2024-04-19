#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Common.h"


void ScenePlay::Init()
{
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
}


void ScenePlay::Step()
{
	player.Step();
	CollisionMapPlayer(mapchip, player);
}



void ScenePlay::Draw()
{
	mapchip.Draw();
	player.Draw();

}


void ScenePlay::Fin()
{

	/*
	g_current_scene_ID = Clear;
	g_current_scene_ID = GameOver;
	*/
}