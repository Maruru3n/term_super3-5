#include "DxLib.h"
#include "../MapChip/MapChip.h"
#include "../Collision/Collision.h"
#include "../Player/player.h"
#include <math.h>

void CollisionMapPlayer(MapChip& mapchip, Player& player)
{
	player.SetJumpFlag(true);

	VECTOR player_pos = { player.GetCurrentPosX() ,player.GetCurrentPosY(),0 };

	if (player_pos.y < 0 || player_pos.y >= SCREEN_SIZE_Y - PLAYER_COLLISION_SIZE)
		return;

	for (int index_y = 0; index_y < MAPCHIP_NUM_Y; index_y++) {
		for (int index_x = 0; index_x < MAPCHIP_NUM_X; index_x++) {
			int mapdata = mapchip.GetMapData(index_y, index_x);
			//ブロックがない又はプレイヤーの初期座標なら何も行わない
			if (mapchip.GetMapData(index_y, index_x) == 0 || mapchip.GetMapData(index_y, index_x) == 1)
				continue;

			VECTOR mapchip_pos = { (float)(index_x * MAPCHIP_SIZE_X) ,(float)(index_y * MAPCHIP_SIZE_Y) };

			if (Collision::IsHitRect(player_pos.x, player_pos.y,
									(float)PLAYER_COLLISION_SIZE, (float)PLAYER_COLLISION_SIZE,
									mapchip_pos.x, mapchip_pos.y,
									MAPCHIP_SIZE_X, MAPCHIP_SIZE_Y)) {

				float overlap_x = 0, overlap_y = 0;

				int direction_num = Collision::GetHitDirection2D(mapchip_pos, MAPCHIP_SIZE_X, MAPCHIP_SIZE_Y,
																player_pos, PLAYER_COLLISION_SIZE, PLAYER_COLLISION_SIZE,
																overlap_x, overlap_y);

				//床が氷ならY座標だけ修正する
				if (mapchip.GetMapData(index_y, index_x) == 4) {
					if (mapchip_pos.y < player_pos.y)
						direction_num = 1;
					else
						direction_num = 3;
				}

				switch (direction_num) {
				case 0: {
					//右から
					float a = player_pos.x + overlap_x;
					player.SetCurrentPosX(player_pos.x + overlap_x);
					player.SetMovePowerX(player.GetMovePowerX() * -1);
					break;
				}
				case 1: {
					//下から
					float a = player_pos.y + overlap_y;
					player.SetCurrentPosY(player_pos.y + overlap_y);
					break;
				}
				case 2: {
					//左から
					float a = player_pos.x - overlap_x;
					player.SetCurrentPosX(player_pos.x - overlap_x);
					player.SetMovePowerX(player.GetMovePowerX() * -1);
					break;
				}
				case 3: {
					//上から
					float a = player_pos.y - overlap_y;
					player.SetCurrentPosY(player_pos.y - overlap_y);
					player.SetJumpFlag();
					//床が通常の床か、ゴールなら横の移動を止める
					if (mapchip.GetMapData(index_y, index_x) == 2 || mapchip.GetMapData(index_y, index_x) == 3) {
						player.SetMoveFlag();
						player.SetMovePowerX(PLAYER_DEFAULT_MOVE_POWER);
						if (mapchip.GetMapData(index_y, index_x) == 3) {
							player.SetGoalFlag();
						}
					}
					//床が氷なら
					if (mapchip.GetMapData(index_y, index_x) == 4) {
						if (player.GetMovePowerX() > 0)
							player.SetMovePowerX(PLAYER_SLOW_MOVE_POWER);
						else
							player.SetMovePowerX(-PLAYER_SLOW_MOVE_POWER);
					}
					break;
				}
				}
			}
		}
	}
}