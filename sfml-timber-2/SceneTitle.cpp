#include "stdafx.h"
#include "SceneTitle.h"

#include "TextGo.h"
#include "SpriteGo.h"
#include "SceneMgr.h"

SceneTitle::SceneTitle() : Scene(SceneIds::Title) {}

SceneTitle::~SceneTitle() {}

void SceneTitle::SetTitleMessage(const std::string& msg)
{
	textTitle.setString(msg);
	Utils::SetOrigin(textTitle, Origins::MC);
}

void SceneTitle::SetIntroMessage(const std::string& msg)
{
	textIntro.setString(msg);
	Utils::SetOrigin(textIntro, Origins::MC);
}

void SceneTitle::Init()
{
	

	texIds.push_back("graphics/main_title.png");
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	fontId = "fonts/KOMIKAP_.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	textTitle.setCharacterSize(250);
	textTitle.setFillColor(sf::Color::Red);
	textTitle.setPosition(bounds.width * 0.5f, bounds.height * 0.5f);

	textIntro.setCharacterSize(50);
	textIntro.setFillColor(sf::Color::White);
	textIntro.setPosition(bounds.width * 0.5f, bounds.height * 0.5f + 400.f);

	AddGameObject(new SpriteGo("graphics/main_title.png"));

	Scene::Init();
}

void SceneTitle::Enter()
{
	Scene::Enter();
	Reset();

	sf::Vector2f size = FRAMEWORK.GetWindowBounds().getSize();
	fadeRect.setSize(size);
	fadeRect.setFillColor(sf::Color(0, 0, 0, 255));
	fadeAlpha = 255;
	fadeIn = true;
	fadeOut = false;
}

void SceneTitle::Reset()
{
	textTitle.setFont(FONT_MGR.Get(fontId));
	textIntro.setFont(FONT_MGR.Get(fontId));
	
	isShowTitleMessage = true;
	isShowIntroMessage = true;
	SetTitleMessage("TIMBER TIME!!!");
	SetIntroMessage("< Press Any Key to Begin >");
}

void SceneTitle::Update(float dt)
{
	if (InputMgr::AnyKeyDown())
	{
		SCENE_MGR.ChangeScene(SceneIds::Mode);
		return;
	}

	if (fadeIn)
	{
		fadeAlpha -= (int)(fadeSpeed * dt);
		if (fadeAlpha <= 0.f)
		{
			fadeAlpha = 0.f;
			fadeIn = false;
		}
		fadeRect.setFillColor(sf::Color(0, 0, 0, (char)fadeAlpha));

	}
	else if (fadeOut)
	{
		fadeAlpha += (int)(fadeSpeed * dt);
		if (fadeAlpha > 255)
		{
			fadeAlpha = 255;
		}
		fadeRect.setFillColor(sf::Color(0, 0, 0, (char)fadeAlpha));
	}
	else
	{
		
	}

	blinkTimer += dt;

	if (blinkTimer >= blinkTime)
	{
		blinkTimer = 0.f;
		Visible = !Visible;
	}

	Scene::Update(dt);
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	window.draw(textTitle);
	if (Visible)
	{
		window.draw(textIntro);
	}
	window.draw(fadeRect);
}