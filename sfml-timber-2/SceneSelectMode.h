#pragma once
class TextGo;

enum class GameMode
{
	None,
	Singleplayer,
	TwoPlayer
};

class SceneSelectMode : public Scene
{
protected:
	int selectedIndex = 0; // 0 = single, 1 = two player
	TextGo* selectorArrow = nullptr;

	sf::Sprite onePlayerSprite;
	sf::Sprite twoPlayerSprite;
	
	sf::Texture tex1;
	sf::Texture tex2;

	TextGo* modetitle;
	TextGo* onePlayerText;
	TextGo* twoPlayerText;

	GameMode selectedMode = GameMode::None;

public:
	SceneSelectMode():Scene(SceneIds::Mode) {}
	~SceneSelectMode()override=default;

	void SetModeTitle(const std::string& msg);

	void Init() override;
	void Update(float dt) override;
	
};
	



