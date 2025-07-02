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
	float timerMax = 30.f;
	
	const int BASESCORE = 200;
	int feverScore1 = BASESCORE;
	int feverScore2 = BASESCORE;
	float fevertimer1 = 0.f;
	float fevertimer2 = 0.f;
	float fevertime = 3.f;

	bool isFever1 = false;
	bool isFever2 = false;

public:
	SceneGame2();
	~SceneGame2() override;

	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	void PlayerOneKeyInput();
	void PlayerTwoKeyInput();

	void PlayerOneCrashCheck();
	void PlayerTwoCrashCheck();

	void TimerUpdate(float dt);
	void FeverTimerUpdate(float dt);

	void Restart();
};

