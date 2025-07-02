#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneTitle.h"
#include "SceneChar.h"

void SceneMgr::Init()
{
	scenes.push_back(new SceneTitle()); //0
	scenes.push_back(new SceneGame()); //1
	scenes.push_back(new SceneChar()); //2  여기도 나중에 공용으로 만져야 하는 구역
	scenes.push_back(new SceneDev1());
	scenes.push_back(new SceneDev2());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		if (scene->Id == currentScene)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}

	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
