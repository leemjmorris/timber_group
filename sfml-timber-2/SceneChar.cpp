#include "stdafx.h"
#include "SceneChar.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "SceneMgr.h"
#include "Player.h"
#include "GameObject.h"

SceneChar::SceneChar() : Scene(SceneIds::Select) {}

SceneChar::~SceneChar() {}

void SceneChar::Init()
{
	texIds.push_back("graphics/char_select.png");
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player2.png");
	texIds.push_back("graphics/player3.png");
	texIds.push_back("graphics/player4.png");

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	fontId = "fonts/KOMIKAP_.ttf";

	AddGameObject(new SpriteGo("graphics/char_select.png"));

	player = (Player*)AddGameObject(new Player());
	player->SetTextureId("graphics/player.png");

	player2 = (Player*)AddGameObject(new Player());
	player2->SetTextureId("graphics/player2.png");

	player3 = (Player*)AddGameObject(new Player());
	player3->SetTextureId("graphics/player3.png");

	player4 = (Player*)AddGameObject(new Player());
	player4->SetTextureId("graphics/player4.png");

	Scene::Init();
}

void SceneChar::SetPosition(const sf::Vector2f& pos)
{
		
}

void SceneChar::SetPlayer()
{

}

void SceneChar::Enter()
{
	Scene::Enter();
	Reset();
}

void SceneChar::Reset()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	float x = bounds.width * 0.5f;
	float y = bounds.height * 0.6f;

	x -= 300.f;

	player->SetPosition({ x + 400.f * (-1.5f), y });
	player2->SetPosition({ x + 400.f * (-0.5f), y });
	player3->SetPosition({ x + 400.f * (0.5f), y });
	player4->SetPosition({ x + 400.f * (1.5f), y });

	player->SetSide(Sides::Right);
	player2->SetSide(Sides::Right);
	player3->SetSide(Sides::Right);
	player4->SetSide(Sides::Right);
}

void SceneChar::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
	{
		SCENE_MGR.ChangeScene(SceneIds::Mode);  // 선택 씬으로 전환
	}

}

void SceneChar::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}

