#include "DxLib.h"
#include "../MapChip/MapChip.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

void CollisionMapPlayer(MapChip& mapchip, Player& player)
{
	//プレイヤーの存在するマップの添え字をだす
	int player_area_num_x = player.GetCurrentPosX() / MAPCHIP_SIZE_X;
	int player_area_num_y = player.GetCurrentPosY() / MAPCHIP_SIZE_Y;
	VECTOR player_pos = { player.GetCurrentPosX() ,player.GetCurrentPosY(),0 };

	for (int index_y = player_area_num_y; index_y <= player_area_num_y + 1; index_y++) {
		for (int index_x = player_area_num_x; index_x <= player_area_num_x + 1; index_x++) {
			if (mapchip.GetMapData(index_y, index_x) != 1)
				continue;

			VECTOR mapchip_pos = { index_x * MAPCHIP_SIZE_X ,index_y * MAPCHIP_SIZE_Y };

			if (Collision::IsHitRect(player_pos.x, player_pos.y,
									player.GetSizeX(), player.GetSizeY(),
									mapchip_pos.x, mapchip_pos.y,
									MAPCHIP_SIZE_X, MAPCHIP_SIZE_Y)) {

				int overlap_x = 0, overlap_y = 0;

				int direction_num = Collision::GetHitDirection2D(mapchip_pos, MAPCHIP_SIZE_X, MAPCHIP_SIZE_Y,
																player_pos, player.GetSizeX(), player.GetSizeY(),
																overlap_x, overlap_y);

				switch (direction_num) {
				case 0: {
					player.SetCurrentPosX(player.GetCurrentPosX() - overlap_x);
					break;
				}
				case 1: {
					player.SetCurrentPosY(player.GetCurrentPosY() - overlap_y);
					break;
				}
				case 2: {
					player.SetCurrentPosX(player.GetCurrentPosX() + overlap_x);
					break;
				}
				case 3: {
					player.SetCurrentPosY(player.GetCurrentPosY() + overlap_y);
					break;
				}
				}
			}
		}
	}
}