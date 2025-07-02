#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;

class SceneGame2 : public Scene
{
protected:
	Player* player1;
	Tree* tree1;
	UiHud* uiHud1;
	Player* player2;
	Tree* tree2;
	UiHud* uiHud2;

	bool isPlaying = false;
	int score1 = 0;
	int score2 = 0;
	float timer1 = 0.f;
	float timerMax = 50.f;

	int count = 0;
	int feverCount = 10;
	float fevertime = 5.f;

public:
	SceneGame2();
	~SceneGame2() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

