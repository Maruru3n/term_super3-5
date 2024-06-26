#include "DxLib.h"
#include "MapChip.h"

MapChip::MapChip()
{
	for (int index_y = 0; index_y < MAPCHIP_NUM_Y; index_y++) {
		for (int index_x = 0; index_x < MAPCHIP_NUM_X; index_x++) {
			m_mapchip_data_num[index_y][index_x] = -1;
		}
	}
	m_stage_index = 0;

	for (int i = 0; i < 3; i++)
		m_mapchip_handle[i] = 0;
}

void MapChip::Init()
{
	LeadFile((char*)MAPCHIP_DATA_PATH[m_stage_index]);
	m_mapchip_handle[0] = LoadGraph("Data/Image/Play/MapChip/Log.png");
	m_mapchip_handle[1] = LoadGraph("Data/Image/Play/MapChip/Goal.png");
	m_mapchip_handle[2] = LoadGraph("Data/Image/Play/MapChip/ice.png");
}
void MapChip::Draw()
{
	for (int index_y = 0; index_y < MAPCHIP_NUM_Y; index_y++) {
		for (int index_x = 0; index_x < MAPCHIP_NUM_X; index_x++) {
			if (m_mapchip_data_num[index_y][index_x] == 2) {
				DrawBox(index_x * MAPCHIP_SIZE_X,
						index_y * MAPCHIP_SIZE_Y,
						(index_x + 1) * MAPCHIP_SIZE_X,
						(index_y + 1) * MAPCHIP_SIZE_Y,
						GetColor(255, 0, 0), true);
				DrawGraph(index_x * MAPCHIP_SIZE_X - 10,
						index_y * MAPCHIP_SIZE_Y,
						m_mapchip_handle[0], true);
			}
			if (m_mapchip_data_num[index_y][index_x] == 3) {
				DrawBox(index_x * MAPCHIP_SIZE_X,
						index_y * MAPCHIP_SIZE_Y,
						(index_x + 1) * MAPCHIP_SIZE_X,
						(index_y + 1) * MAPCHIP_SIZE_Y,
						GetColor(0, 255, 0), true);
				DrawGraph(index_x * MAPCHIP_SIZE_X - 10,
							index_y * MAPCHIP_SIZE_Y,
							m_mapchip_handle[1], true);
			}
			if (m_mapchip_data_num[index_y][index_x] == 4) {
				DrawBox(index_x * MAPCHIP_SIZE_X,
						index_y * MAPCHIP_SIZE_Y,
						(index_x + 1) * MAPCHIP_SIZE_X,
						(index_y + 1) * MAPCHIP_SIZE_Y,
						GetColor(0, 0, 255), true);
				DrawGraph(index_x * MAPCHIP_SIZE_X,
							index_y * MAPCHIP_SIZE_Y,
							m_mapchip_handle[2], false);
			}
		}
	}
}
void MapChip::Fin()
{

}

void MapChip::LeadFile(char* file_name)
{
	FILE* fp;
	errno_t err;
	int index_x = 0, index_y = 0;

	err = fopen_s(&fp, file_name, "r");

	if (err != NULL)
		return;

	while (index_y < MAPCHIP_NUM_Y) {
		char work = fgetc(fp);

		if (work == ',')
			index_x++;
		else if (work == '\n') {
			index_x = 0;
			index_y++;
		}
		else
			m_mapchip_data_num[index_y][index_x] = work - '0';
	}

	fclose(fp);
}