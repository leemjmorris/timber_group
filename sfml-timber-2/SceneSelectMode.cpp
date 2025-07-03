#include "stdafx.h"
#include "SceneSelectMode.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"


void SceneSelectMode::SetModeTitle(const std::string& msg)
{
	if (modetitle == nullptr) // Check if modetitle is initialized
	{
		std::cerr << "Error: modetitle is not initialized!" << std::endl;
		return;
	}
	
	modetitle->SetString(msg);
	modetitle->SetCharacterSize(48);
	modetitle->SetFillColor(sf::Color::White);
	modetitle->SetPosition({ 200.0f, 50.0f });
}
void SceneSelectMode::Init()
{
	texIds.push_back("graphics/game_mode.jpg");
	AddGameObject(new SpriteGo("graphics/game_mode.jpg"));

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	selectorArrow = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	selectorArrow->SetString("->");
	selectorArrow->SetCharacterSize(36);
	selectorArrow->SetFillColor(sf::Color::Red);

	modetitle = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	modetitle->SetString("TIMBER GAME");
	modetitle->SetCharacterSize(72);
	modetitle->SetFillColor(sf::Color::White);
	modetitle->SetPosition({ 720.0f, 350.f });

	onePlayerText = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	onePlayerText->SetString("1. Single Player");
	onePlayerText->SetCharacterSize(36);
	onePlayerText->SetFillColor(sf::Color::White);
	onePlayerText->SetPosition({ 800.0f, 530.0f });

	twoPlayerText = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	twoPlayerText->SetString("2. Two Player");
	twoPlayerText->SetCharacterSize(36);
	twoPlayerText->SetFillColor(sf::Color::White);
	twoPlayerText->SetPosition({ 800.0f, 630.0f });

	Scene::Init();
}

void SceneSelectMode::Enter()
{
	Scene::Enter();

	selectorArrow->SetPosition({ 760.0f, 530.0f });
	SoundMgr::soundModeSelect.play();

}


void SceneSelectMode::Update(float dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Up)||InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		selectedIndex = 0;
		selectedMode = GameMode::Singleplayer;
	}
		
	else if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		selectedIndex = 1;
		selectedMode = GameMode::TwoPlayer;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		if (selectedMode == GameMode::Singleplayer)
		{
			SoundMgr::soundModeSelect.pause();
			SCENE_MGR.ChangeScene(SceneIds::Game);
		}
		else if (selectedMode == GameMode::TwoPlayer)
		{
			SCENE_MGR.ChangeScene(SceneIds::Select); 
			SoundMgr::soundModeSelect.pause();
		}
	}
	
	if (InputMgr::GetKeyDown(sf::Keyboard::Up))
	{
		selectedIndex = std::max(0, selectedIndex - 1);
		selectedMode = GameMode::Singleplayer;
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Down))
	{
		selectedIndex = std::min(1, selectedIndex + 1);
		selectedMode = GameMode::TwoPlayer;
	}

	
	if (selectorArrow != nullptr)
	{
		if (selectedIndex == 0)
			selectorArrow->SetPosition({ 760.0f, 530.0f });
		else
			selectorArrow->SetPosition({ 760.0f, 630.0f });
	}

	if (selectedIndex == 0)
	{
		onePlayerText->SetCharacterSize(50);
		twoPlayerText->SetCharacterSize(36);
		onePlayerText->SetFillColor(sf::Color::Yellow);
		twoPlayerText->SetFillColor(sf::Color::White);
	}
	else
	{
		onePlayerText->SetCharacterSize(36);
		twoPlayerText->SetCharacterSize(50);
		onePlayerText->SetFillColor(sf::Color::White);
		twoPlayerText->SetFillColor(sf::Color::Yellow);
	}
}



