#pragma once
#include "DxLib.h"

//長さの差を返す
float GetDefLen_f(float pos_A, float pos_B);
//≒
bool NearyEqual(float num1, float num2, float error_num = 1.0f);

//桁数を返す
int GetNumLen(int num);

//----------------------------------------------------------------------------------------------------------
//ベクトル
/*
VAdd( VECTOR vec1, VECTOR vec2 );		加算
VSub( VECTOR vec1, VECTOR vec2 );		減算
VScale( VECTOR vec, float Scale );		定数倍
VSize( VECTOR vec );					サイズ取得
VNorm( VECTOR vec );					正規化
VDot( VECTOR vec1, VECTOR vec2 );		内積
VCross( VECTOR vec1, VECTOR vec2 );		外積3D
*/

//外積2D
float VCross2D(VECTOR vec1, VECTOR vec2);

//現在地から目的地まで指定の速さで動くベクトル
VECTOR GetVector(VECTOR vec_here, VECTOR vec_dis, float speed = 1.0f);

//ベクトルのなす角
float AngleOf2Vector(VECTOR vec1, VECTOR vec2, bool degree_switch = false);
//----------------------------------------------------------------------------------------------------------