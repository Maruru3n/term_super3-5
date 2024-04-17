#pragma once
#include "../Common.h"

constexpr int MAPCHIP_NUM_X = 16;
constexpr int MAPCHIP_NUM_Y = 9;

constexpr int MAPCHIP_SIZE_X = SCREEN_SIZE_X / 16;
constexpr int MAPCHIP_SIZE_Y = SCREEN_SIZE_Y / 9;

constexpr int STAGE_NUM = 1;

constexpr char MAPCHIP_DATA_PATH[STAGE_NUM][64] = {
	{"Data/Image/MapChip/stage1.csv"},
};

class MapChip
{
private:
	int m_mapchip_data_num[MAPCHIP_NUM_Y][MAPCHIP_NUM_X];
	int m_stage_index;

public:
	MapChip();

	void Init();
	void Draw();
	void Fin();

	void LeadFile(char* file_name);

	int GetMapData(int index_y, int index_x) { return m_mapchip_data_num[index_y][index_x]; }
};