#pragma once
#include "GameObject.h"

class Player : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Sprite axe;
	sf::Sprite aura;

	Sides side = Sides::Right;

	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> scales;
	std::vector<sf::Vector2f> axePositions;
	std::vector<sf::Vector2f> auraPositions;

	std::string texPlayerId;
	std::string ripTexId;
	std::string axeTexId;
	std::string auraTexId;

	bool isAlive = true;
	bool drawAxe = false;
	bool drawAura = false;

	PlayerSlot slot = PlayerSlot::Single;

public:
	Player(const std::string& name = "");
	~Player() override = default;
	
	void SetAlive(bool alive);
	void SetDrawAxe(bool draw) { drawAxe = draw; }
	void SetDrawAura(bool draw) { drawAura = draw; }

	void SetSide(Sides s);
	Sides GetSide() const { return side; }

	void SetPosition(const sf::Vector2f& pos) override;
	void SetTextureId(const std::string& id) { texPlayerId = id; }

	void SetPlaySlot(PlayerSlot s) { slot = s; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

