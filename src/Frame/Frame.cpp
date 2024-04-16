#include "DxLib.h"
#include "../Common.h"
#include "Frame.h"

//メインループの最初にかく
/*
//=====================================================================
Sleep(1);	//システムに処理を返す

//現在の時間を取得
frameRateInfo.currentTime = GetNowCount();

//最初のループなら、
//現在の時間を、FPSの計算をした時間に設定
if (frameRateInfo.calcFpsTime == 0.0f)
{
	frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	frameRateInfo.fps = (float)FRAME_RATE;
}

// 現在の時間が、前回のフレーム時より
// 100/60ミリ秒（1/60秒）以上経過していたら処理を実行する
if (frameRateInfo.currentTime - frameRateInfo.LastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.LastFrameTime = frameRateInfo.currentTime;

			//フレーム数をカウント
			frameRateInfo.count++;
//=====================================================================
*/

//フリップ関数の上にかく
/*
//FPS計算
CalcFPS();

//FPS表示
DrawFPS();
*/

FrameRateInfo frameRateInfo;

void CalcFPS()
{
	//前回のFPSを計算した時間からの経過時間を求める
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//前回のFPSを計算した時間から
	//１秒以上経過していたらFPSを計算する
	if (difTime > 1000)
	{
		//フレーム回数をミリ秒に合わせる
		//小数まで出したいのでfloatにキャスト
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPSを求める
		//理想の数値は 60000 / 1000 で 60 となる
		frameRateInfo.fps = frameCount / difTime;

		//フレームレートカウントをクリア
		frameRateInfo.count = 0;

		//FPSを計算した時間を更新
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

void DrawFPS()
{
	DrawFormatString(0, SCREEN_SIZE_Y - 15, GetColor(255,255,255), DRAW_FPS, frameRateInfo.fps);
}