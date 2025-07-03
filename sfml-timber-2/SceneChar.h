#pragma once

class Player;

class SceneChar :  public Scene
{
protected:
	Player* player;
	Player* player2;
	Player* player3;
	Player* player4;

	int index1 = 3;
	int index2 = 0;

	sf::Text textP1;
	sf::Text textP2;
	sf::Text textSelectGuide;

	bool isShowP1Message;
	bool isShowP2Message;
	bool isP1Selected = false;
	bool isP2Selected = false;

	std::string fontId;
	std::vector<Player*> characters;

public:
	static std::string p1;
	static std::string p2;

	SceneChar();
	~SceneChar() override;

	void SetPosition(const sf::Vector2f& pos);
	void SetPlayer();

	void SetP1Message(const std::string& msg);
	void SetP2Message(const std::string& msg);
	void SetGuideMessage(const std::string& msg);
	void SetShowP1Message(bool show) { isShowP1Message = show; }
	void SetShowP2Message(bool show) { isShowP2Message = show; }

	void Init() override;
	void Enter() override;
	void Reset();
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

