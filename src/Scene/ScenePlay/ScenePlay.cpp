#include "DxLib.h"
#include "ScenePlay.h"
#include "../../Common.h"



void ScenePlay::Init()
{


	player.Init();


}


void ScenePlay::Step()
{



	player.Step();


}



void ScenePlay::Draw()
{

	player.Draw();



}


void ScenePlay::Fin()
{


	/*
	g_current_scene_ID = Clear;
	g_current_scene_ID = GameOver;
	*/
}