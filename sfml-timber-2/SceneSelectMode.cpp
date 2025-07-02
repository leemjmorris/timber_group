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
	texIds.push_back("graphics/background.png");
	AddGameObject(new SpriteGo("graphics/background.png"));

	fontIds.push_back("fonts/KOMIKAP_.ttf");
	

	modetitle = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	modetitle->SetString("TIMBER GAME");
	//텍스트 설정
	modetitle->SetCharacterSize(72);
	modetitle->SetFillColor(sf::Color::White);
	modetitle->SetPosition({ 200.0f, 50.f });


	//모드 선택 텍스트
	onePlayerText = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	onePlayerText->SetString("1. Single Player");
	onePlayerText->SetCharacterSize(36);
	onePlayerText->SetFillColor(sf::Color::White);
	onePlayerText->SetPosition({ 150.0f, 200.0f });

	twoPlayerText = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	twoPlayerText->SetString("2. Two Player");
	twoPlayerText->SetCharacterSize(36);
	twoPlayerText->SetFillColor(sf::Color::White);
	twoPlayerText->SetPosition({ 150.0f, 280.0f });

	
}
void SceneSelectMode::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);  // 게임 씬으로 전환
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		selectedMode = GameMode::Singleplayer;
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	{
		selectedMode = GameMode::TwoPlayer;
		SCENE_MGR.ChangeScene(SceneIds::Dev2);
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



