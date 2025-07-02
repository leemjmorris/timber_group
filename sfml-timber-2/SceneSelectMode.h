#pragma once
#include "Scene.h"
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
	sf::Sprite onePlayerSprite;
	sf::Sprite twoPlayerSprite;
	
	sf::Texture tex1;
	sf::Texture tex2;

	TextGo* modetitle;
	TextGo* onePlayerText;
	TextGo* twoPlayerText;

	GameMode selectedMode = GameMode::None;

public:
	SceneSelectMode():Scene(SceneIds::Select) {}
	~SceneSelectMode()override=default;

	void SetModeTitle(const std::string& msg);

	void Init() override;
	void Update(float dt) override;
	/*void Draw(sf::RenderWindow& window) override;*/
};
	



