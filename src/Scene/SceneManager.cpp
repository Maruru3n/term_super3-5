#include "DxLib.h"
#include "../Common.h"
#include "SceneManager.h"
#include "SceneTitle/SceneTitle.h"
#include "ScenePlay/ScenePlay.h"
#include "SceneClear/SceneClear.h"
#include "SceneGameOver/SceneGameOver.h"


//コンストラクタ
SceneManager::SceneManager()
{
	scene = nullptr;
}


//シーン遷移メイン処理
void SceneManager::Main()
{

	switch (g_current_scene_ID) {
	case Title: {//タイトル
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneTitle;
		scene->Init();

		g_current_scene_ID = LOOP;

		break;
	}
	case Play: {//プレイ
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new ScenePlay;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	case GameOver: {//ゲームオーバー
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneGameOver;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	case Clear: {//クリア
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneClear;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	default: {//通常処理
		scene->Step();
		scene->Draw();
	}
	}
}