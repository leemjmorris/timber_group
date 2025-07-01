#include "stdafx.h"
#include "UiHud.h"

UiHud::UiHud(const std::string& name)
	: GameObject(name)
{
}

void UiHud::SetScore(int score)
{
	static std::string formatScore = "SCORE: ";
	textScore.setString(formatScore + std::to_string(score));
	Utils::SetOrigin(textScore, Origins::TL);
}

void UiHud::SetMessage(const std::string& msg)
{
	textMessage.setString(msg);
	Utils::SetOrigin(textMessage, Origins::MC);
}

void UiHud::SetTimeBar(float value)
{
	timeBar.setSize({ timeBarSize.x * value, timeBarSize.y });
}

void UiHud::Init()
{
	fontId = "fonts/KOMIKAP_.ttf";

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();

	textScore.setCharacterSize(100);
	textScore.setFillColor(sf::Color::White);

	textMessage.setCharacterSize(100);
	textMessage.setFillColor(sf::Color::White);
	textMessage.setPosition(bounds.width * 0.5f, bounds.height * 0.5f);

	timeBarSize = { 400.f, 80.f };
	timeBar.setFillColor(sf::Color::Red);
	timeBar.setSize(timeBarSize);

	Utils::SetOrigin(timeBar, Origins::BL);
}

void UiHud::Release()
{
}

void UiHud::Reset()
{
	textScore.setFont(FONT_MGR.Get(fontId));
	textMessage.setFont(FONT_MGR.Get(fontId));

	SetScore(0);
	isShowMessage = true;
	SetMessage("Message!");
	SetTimeBar(1.f);

	// 0,1,2 ·Î ºÐ±â
	textScore.setPosition(20, 20);
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	timeBar.setPosition(bounds.width * 0.5f - timeBarSize.x * 0.5f, bounds.height - 100.f);
}

void UiHud::Update(float dt)
{
}

void UiHud::Draw(sf::RenderWindow& window)
{
	window.draw(textScore);
	if (isShowMessage)
	{
		window.draw(textMessage);
	}
	window.draw(timeBar);
}
