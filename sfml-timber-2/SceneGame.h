#pragma once
class Player;
class Tree;
class UiHud;

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;
	UiHud* uiHud;

	bool isPlaying = false;
	int score = 0;
	float timer = 0.f;
	float timerMax = 5.f;

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

