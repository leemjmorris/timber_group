#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& name)
	: GameObject(name)
{
}

void Player::SetAlive(bool alive)
{
	isAlive = alive;
	if (isAlive)
	{
		sprite.setTexture(TEXTURE_MGR.Get(texPlayerId));
	}
	else
	{
		sprite.setTexture(TEXTURE_MGR.Get(ripTexId));
		sprite.setScale({ 1.f, 1.f });
		drawAxe = false;
		drawAura = false;
	}
	Utils::SetOrigin(sprite, Origins::BC);
}

void Player::SetSide(Sides s)
{
	side = s;

	sprite.setPosition(position + positions[(int)side]);
	sprite.setScale(scales[(int)side]);

	axe.setPosition(position + axePositions[(int)side]);
	axe.setScale(scales[(int)side]);

	aura.setPosition(position + auraPositions[(int)side]);
	sf::Vector2f auraScale = scales[(int)side];
	auraScale.x *= 1.5f;
	aura.setScale(auraScale);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position + positions[(int)side]);
	axe.setPosition(position + axePositions[(int)side]);
	aura.setPosition(position + auraPositions[(int)side]);
}

void Player::Init()
{
	if (texPlayerId.empty())
	{
		texPlayerId = "graphics/player.png";
	}

	axeTexId = "graphics/axe.png";
	ripTexId = "graphics/rip.png";
	auraTexId = "graphics/aura.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f, 0.f };
	positions[(int)Sides::Right] = { 300.f, 0.f };

	scales.resize(2);
	scales[(int)Sides::Left] = { -1.f, 1.f };
	scales[(int)Sides::Right] = { 1.f, 1.f };

	axePositions.resize(2);
	axePositions[(int)Sides::Left] = { -165.f, -55.f };
	axePositions[(int)Sides::Right] = { 165.f, -55.f };
	
	auraPositions.resize(2);
	auraPositions[(int)Sides::Left] = { -290.f, 20.f };
	auraPositions[(int)Sides::Right] = { 290.f, 20.f };
}

void Player::Release()
{
}

void Player::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texPlayerId));
	Utils::SetOrigin(sprite, Origins::BC);

	axe.setTexture(TEXTURE_MGR.Get(axeTexId));
	Utils::SetOrigin(axe, Origins::BC);

	aura.setTexture(TEXTURE_MGR.Get(auraTexId));
	aura.setScale({ 1.5f,1.f });
	Utils::SetOrigin(aura, Origins::BC);

	SetSide(Sides::Right);
	drawAura = false;
}

void Player::Update(float dt)
{

}

void Player::Draw(sf::RenderWindow& window)
{
	if (drawAura)
	{
		window.draw(aura);
	}

	window.draw(sprite);

	if (drawAxe)
	{
		window.draw(axe);
	}
}
