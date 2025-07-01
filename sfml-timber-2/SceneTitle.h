#pragma once
#include "Scene.h"
class SceneTitle :  public Scene
{
protected:
	bool press_any_key = false;
	bool ready = false;
	sf::Text textTitle;
	sf::Text textIntro;

	std::string fontId;

	bool isShowTitleMessage;
	bool isShowIntroMessage;

	float blinkTimer = 0.f;
	float blinkTime = 0.5f;
	bool Visible = true;

	sf::RectangleShape fadeRect;
	int fadeAlpha = 255;
	float fadeSpeed = 255.f;

	bool fadeIn = true;
	bool fadeOut = false;

public:
	SceneTitle();
	~SceneTitle() override;

	void SetTitleMessage(const std::string& msg);
	void SetIntroMessage(const std::string& msg);
	void SetShowTitleMessage(bool show) { isShowTitleMessage = show; }
	void SetShowIntroMessage(bool show) { isShowIntroMessage = show; }

	void Init() override;
	void Enter() override;
	void Reset();
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

