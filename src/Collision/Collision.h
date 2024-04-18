#pragma once
#include "DxLib.h"


class Collision {
public:

	//“–‚½‚Á‚Ä‚¢‚é‚Æ‚«‚Ç‚Ì•ûŒü‚©‚ç“–‚½‚Á‚Ä‚¢‚é‚©
	static int GetHitDirection2D(VECTOR objects, int size_x1, int size_y1, VECTOR use, int size_x2, int size_y2, float& overlap_x, float& overlap_y);

	//‹éŒ`‚Ì“–‚½‚è”»’è
	static bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

	//‰~‚Ì“–‚½‚è”»’è
	static bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);

	//‰~‚Æ‹éŒ`‚Ì“–‚½‚è”»’è
	static bool IsHitCircleRect(float x1, float y1, float r1, float x2, float y2, float w2, float h2);

	//‹éŒ`‚Æ“_‚Ì“–‚½‚è”»’è
	static bool IsHitRectPoint(float rect_x, float rect_y, float rect_w, float rect_h, float point_pos_x, float point_pos_y);

	//‰~‚Æ“_‚Ì“–‚½‚è”»’è
	static bool IsHitCirclePoint(float circcle_pos_x, float circcle_pos_y, float circle_len, float point_pos_x, float point_pos_y);

	//‰~‚Æü‚Ì“–‚½‚è”»’è
	static bool IsHitCircleLine(float circle_x, float circle_y, float circle_len,
		float line_start_x, float line_start_y, float line_end_x, float line_end_y);
};