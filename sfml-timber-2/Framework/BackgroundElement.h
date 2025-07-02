#pragma once
#include "SpriteGo.h"

class BackgroundElement : public SpriteGo
{
public:
	enum class MoveType
	{
		Linear,
		Wave,
	};

protected:
	MoveType moveType = MoveType::Linear;

	float amplitude = 0.f;
	float frequency = 0.f;
	float timer = 0.f;

	sf::Vector2f startPos;

public:
	BackgroundElement(const std::string& texPlayerId = "", const std::string& name = "");

	float speed = 0.f;
	sf::Vector2f direction;

	float minScale = 0.5f;
	float maxScale = 2.f;

	float minY = 100;
	float maxY = 400;

	float minSpeed = 100;
	float maxSpeed = 200;

	void SetSide(Sides side);
	void SetMoveType(MoveType type);

	void Reset() override;
	void Update(float dt) override;
};

