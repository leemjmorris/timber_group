#pragma once
#include "GameObject.h"
class Tree : public GameObject
{
protected:
	sf::Sprite tree;
	std::vector<sf::Sprite> branches;
	std::vector<Sides> branchesSide;
	std::vector<sf::Sprite> logs;
	std::vector<Sides> logSide;

	std::vector<sf::Vector2f> logVec;

	std::string texIdTree;
	std::string texIdBranch;
	std::string texIdLog;
	int logIndex = 0;
	const int LOGCOUNT = 10;

public:
	Tree() = default;
	~Tree() override = default;

	void SetPosition(const sf::Vector2f& pos) override;
	Sides UpdateBranches();
	void UpdateLogSide(Sides side);

	Sides GetSide() const { return branchesSide[branchesSide.size() - 1]; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

