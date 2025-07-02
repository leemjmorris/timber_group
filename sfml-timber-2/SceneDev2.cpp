#include "stdafx.h"
#include "SceneDev2.h"
#include "TextGo.h"

SceneDev2::SceneDev2()
	: Scene(SceneIds::Game2)
{
}

void SceneDev2::Init()
{
	/*fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Dev2");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	Scene::Init();*/
}

void SceneDev2::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		SCENE_MGR.ChangeScene(SceneIds::Mode);
	}
}