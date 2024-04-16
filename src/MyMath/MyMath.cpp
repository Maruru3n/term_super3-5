#include "DxLib.h"
#include "MyMath.h"
#include <math.h>

//長さの差を返す
float GetDefLen_f(float pos_A, float pos_B) { return fabsf(pos_A - pos_B); }

// ≒
bool NearyEqual(float num1, float num2, float error_num)
{
	if (fabsf(num1 - num2) < error_num)
		return true;

	return false;
}

//桁数を返す
int GetNumLen(int num)
{
	int len = 0;
	if (num == 0)
		return 1;
	else
		while (num != 0){
			num /= 10;
			len++;
		}

	return len;
}

//現在地から目的地まで指定の速さで動くベクトル
VECTOR GetVector(VECTOR vec_here, VECTOR vec_dis, float speed)
{
	//現在地から目的地のベクトル
	VECTOR sub_vec = VSub(vec_dis, vec_here);

	//正規化
	VECTOR nor_vec = VNorm(sub_vec);

	//取得するベクトルの大きさ
	VECTOR mul_vec = VScale(nor_vec, speed);

	return mul_vec;
}

//外積
float VCross2D(VECTOR vec1, VECTOR vec2)
{
	return (vec1.x * vec2.y - vec1.y * vec2.x);
}

//ベクトルのなす角
float AngleOf2Vector(VECTOR vec1, VECTOR vec2,bool degree_switch)
{
	//ベクトルの長さ
	double len1 = VSize(vec1);
	double len2 = VSize(vec2);

	//cosθ
	double cos_sita = VDot(vec1, vec2) / (len1 * len2);

	//θ
	double sita = acos(cos_sita);

	//角度
	if (degree_switch)
		sita = sita * 180.0 / DX_PI;

	return (float)sita;
}