#include "stdafx.h"
#include "SceneChar.h"
#include "TextGo.h"
#include "SpriteGo.h"
#include "SceneMgr.h"
#include "Player.h"
#include "GameObject.h"

std::string SceneChar::p1;
std::string SceneChar::p2;

SceneChar::SceneChar() : Scene(SceneIds::Select) {}

SceneChar::~SceneChar() {}


void SceneChar::Init()
{
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	texIds.push_back("graphics/char_select.jpg");
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player2.png");
	texIds.push_back("graphics/player3.png");
	texIds.push_back("graphics/player4.png");

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	fontId = "fonts/KOMIKAP_.ttf";

	AddGameObject(new SpriteGo("graphics/char_select.jpg"));

	player = (Player*)AddGameObject(new Player());
	player->SetTextureId("graphics/player.png");

	player2 = (Player*)AddGameObject(new Player());
	player2->SetTextureId("graphics/player2.png");

	player3 = (Player*)AddGameObject(new Player());
	player3->SetTextureId("graphics/player3.png");

	player4 = (Player*)AddGameObject(new Player());
	player4->SetTextureId("graphics/player4.png");

	textP1.setCharacterSize(25);
	textP1.setFillColor(sf::Color::Red);

	textP2.setCharacterSize(25);
	textP2.setFillColor(sf::Color::Blue);

	textSelectGuide.setCharacterSize(70);
	textSelectGuide.setFillColor(sf::Color::White);

	Scene::Init();
}

void SceneChar::SetPosition(const sf::Vector2f& pos)
{
		
}

void SceneChar::SetPlayer()
{

}

void SceneChar::SetP1Message(const std::string& msg)
{
	textP1.setString(msg);
	Utils::SetOrigin(textP1, Origins::MC);
}

void SceneChar::SetP2Message(const std::string& msg)
{
	textP2.setString(msg);
	Utils::SetOrigin(textP2, Origins::MC);
}

void SceneChar::SetGuideMessage(const std::string& msg)
{
	textSelectGuide.setString(msg);
	Utils::SetOrigin(textSelectGuide, Origins::MC);
}

void SceneChar::Enter()
{
	Scene::Enter();
	Reset();

	SoundMgr::soundCharSelect.play();
}

void SceneChar::Reset()
{
	characters = { player, player2, player3, player4 };

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

	textP1.setFont(FONT_MGR.Get(fontId));
	textP1.setPosition(player4->GetPosition().x + 300.f, bounds.height * 0.5f - 125.f);

	textP2.setFont(FONT_MGR.Get(fontId));
	textP2.setPosition(player->GetPosition().x + 300.f, bounds.height * 0.5f - 125.f);

	textSelectGuide.setFont(FONT_MGR.Get(fontId));
	textSelectGuide.setPosition(x + 300.f, y - 400.f);

	isShowP1Message = true;
	isShowP2Message = true;

	isP1Selected = false;
	isP2Selected = false;
	index1 = 3;
	index2 = 0;

	SetP1Message("Player 2");
	SetP2Message("Player 1");
	SetGuideMessage("P1 [ ENTER ]           P2 [ L-SHIFT ]");
}


void SceneChar::Update(float dt)
{
	Scene::Update(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
	{
		SCENE_MGR.ChangeScene(SceneIds::Mode);
		SoundMgr::soundCharSelect.pause();
	}

	if (!isP2Selected)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::A))
		{
			if (index2 != 0)
			{
				index2--;
				sf::Vector2f pos = textP2.getPosition();
				pos.x -= 400.f;
				textP2.setPosition(pos);
			}
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::D))
		{
			if (index2 != 3)
			{
				index2++;
				sf::Vector2f pos = textP2.getPosition();
				pos.x += 400.f;
				textP2.setPosition(pos);
			}
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::LShift))
		{
			SoundMgr::soundP1Select.play();
			switch (index2)
			{
			case 0:
				p2 = "graphics/player.png";
				break;
			case 1:
				p2 = "graphics/player2.png";
				break;
			case 2:
				p2 = "graphics/player3.png";
				break;
			case 3:
				p2 = "graphics/player4.png";
				break;
			}
			isP2Selected = true;
		}
	}

	if (!isP1Selected)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			if (index1 != 0)
			{
				index1--;
				sf::Vector2f pos = textP1.getPosition();
				pos.x -= 400.f;
				textP1.setPosition(pos);
			}
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			if (index1 != 3)
			{
				index1++;
				sf::Vector2f pos = textP1.getPosition();
				pos.x += 400.f;
				textP1.setPosition(pos);
			}
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			SoundMgr::soundP2Select.play();
			switch (index1)
			{
				case 0:
					p1 = "graphics/player.png";
					break;
				case 1:
					p1 = "graphics/player2.png";
					break;
				case 2:
					p1 = "graphics/player3.png";
					break;
				case 3:
					p1 = "graphics/player4.png";
					break;
			}
			isP1Selected = true;
		}
	}	

	if (isP1Selected && isP2Selected)
	{
		SCENE_MGR.ChangeScene(SceneIds::Game2);
		SoundMgr::soundCharSelect.pause();
	}
}

void SceneChar::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	window.draw(textP1);
	window.draw(textP2);
	window.draw(textSelectGuide);
}

