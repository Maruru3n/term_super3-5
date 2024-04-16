#pragma once

//設定フレームレート（60FPS）
#define FRAME_RATE (60)

//１フレームの時間（ミリ秒）
#define FRAME_TIME (1000/FRAME_RATE)

// FPSの表示
#define DRAW_FPS "FPS[%.2f]"

//フレームレート情報
struct FrameRateInfo
{
	int currentTime;	//現在の時間
	int LastFrameTime;	//前回のフレーム実行時の時間
	int count;			//フレームカウント用
	int calcFpsTime;	//FPSを計算した時間
	float fps;			//計測したFPS（表示用）
};

//フレームレート情報変数
extern FrameRateInfo frameRateInfo;

//FPS計算
void CalcFPS();

//FPS表示（デバック用）
void DrawFPS();