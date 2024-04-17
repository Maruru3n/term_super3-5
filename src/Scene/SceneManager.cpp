#include "DxLib.h"
#include "../Common.h"
#include "SceneManager.h"
#include "SceneTitle/SceneTitle.h"
#include "ScenePlay/ScenePlay.h"
#include "SceneClear/SceneClear.h"
#include "SceneGameOver/SceneGameOver.h"

SceneManager::SceneManager()
{
	scene = nullptr;
}

void SceneManager::Main()
{
	switch (g_current_scene_ID) {
	case Title: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneTitle;
		scene->Init();

		g_current_scene_ID = LOOP;

		break;
	}
	case Play: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new ScenePlay;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	case GameOver: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneGameOver;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	case Clear: {
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneClear;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	default: {

		
	}
	}
}