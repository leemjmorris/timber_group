#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Player.h"

class player;

class SceneChar :  public Scene
{
protected:	

	Player* player;
	Player* player2;
	Player* player3;
	Player* player4;

	sf::Text textPlayerNum;
	sf::Text textSelectGuide;

	std::string fontId;

public:
	SceneChar();
	~SceneChar() override;

	void SetPosition(const sf::Vector2f& pos);
	void SetPlayer();

	void Init() override;
	void Enter() override;
	void Reset();
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

