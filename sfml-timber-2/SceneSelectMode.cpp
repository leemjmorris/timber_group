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
	modetitle->SetPosition({ 200.0f, 50.0f }); // 원하는 위치로 조정
}
void SceneSelectMode::Init()
{	//폰트 가져오기
	texIds.push_back("graphics/game_mode.jpg");
	AddGameObject(new SpriteGo("graphics/game_mode.jpg"));
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	//1,2번 선택 화살표
	selectorArrow = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	selectorArrow->SetString("->");
	selectorArrow->SetCharacterSize(36);
	selectorArrow->SetFillColor(sf::Color::Red);
	selectorArrow->SetPosition({ 760.0f, 530.0f }); // 1번 위치

	//텍스트 설정
	modetitle = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	modetitle->SetString("TIMBER GAME");
	modetitle->SetCharacterSize(72);
	modetitle->SetFillColor(sf::Color::White);
	modetitle->SetPosition({ 720.0f, 350.f });


	//모드 선택 텍스트
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

	
}
void SceneSelectMode::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);  // 게임 씬으로 전환
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Up)||InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		selectedIndex = 0;
		selectedMode = GameMode::Singleplayer;
		/*SCENE_MGR.ChangeScene(SceneIds::Game); */
	}
		
	else if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		selectedIndex = 1;
		selectedMode = GameMode::TwoPlayer;
		/*SCENE_MGR.ChangeScene(SceneIds::Select);*/
	}

	// Enter로 선택 확정
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		if (selectedMode == GameMode::Singleplayer)
		{
			SCENE_MGR.ChangeScene(SceneIds::Game);
		}
		else if (selectedMode == GameMode::TwoPlayer)
		{
			SCENE_MGR.ChangeScene(SceneIds::Select); 
		}
	}
	//업다운 이동로직
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

	// 선택된 위치로 화살표 이동
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

//void SceneSelectMode::Draw(sf::RenderWindow& window)
//{
	/*window.clear(sf::Color::Black);

	window.draw(modetitle);
	window.draw(onePlayerText);
	window.draw(twoPlayerText);
	window.draw(onePlayerSprite);
	window.draw(twoPlayerSprite);*/
//}



