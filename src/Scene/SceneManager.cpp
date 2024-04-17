#include "DxLib.h"
#include "../Common.h"
#include "SceneManager.h"
#include "SceneTitle/SceneTitle.h"
#include "ScenePlay/ScenePlay.h"
#include "SceneClear/SceneClear.h"
#include "SceneGameOver/SceneGameOver.h"


//�R���X�g���N�^
SceneManager::SceneManager()
{
	scene = nullptr;
}


//�V�[���J�ڃ��C������
void SceneManager::Main()
{

	switch (g_current_scene_ID) {
	case Title: {//�^�C�g��
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneTitle;
		scene->Init();

		g_current_scene_ID = LOOP;

		break;
	}
	case Play: {//�v���C
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new ScenePlay;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	case GameOver: {//�Q�[���I�[�o�[
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneGameOver;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	case Clear: {//�N���A
		if (scene != nullptr) {
			scene->Fin();
			delete scene;
		}

		scene = new SceneClear;
		scene->Init();

		g_current_scene_ID = LOOP;
		break;
	}
	default: {//�ʏ폈��
		scene->Step();
		scene->Draw();
	}
	}
}