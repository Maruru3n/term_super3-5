#include "DxLib.h"
#include "../MapChip/MapChip.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"

void CollisionMapPlayer(MapChip& mapchip, VECTOR player_pos)
{
	int player_area_num_x = player_pos.x / MAPCHIP_SIZE_X;
	int player_area_num_y = player_pos.y / MAPCHIP_SIZE_Y;

	for (int index_y = player_area_num_y; index_y <= player_area_num_y + 1; index_y++) {
		for (int index_x = player_area_num_x; index_x <= player_area_num_x + 1; index_x++) {
			if (mapchip.GetMapData(index_y, index_x) != 1)
				continue;

			if (Collision::IsHitRect(index_x * MAPCHIP_SIZE_X,
				index_y * MAPCHIP_SIZE_Y,
				MAPCHIP_SIZE_X,
				MAPCHIP_SIZE_Y,
				player_pos.x,
				player_pos.y,
				PLAYER_COLLISION_SIZE,
				PLAYER_COLLISION_SIZE)) {

			}
		}
	}
}