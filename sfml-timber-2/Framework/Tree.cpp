#include "stdafx.h"
#include "Tree.h"

void Tree::SetPosition(const sf::Vector2f& pos)
{
	position = pos;

	tree.setPosition(pos);
	for (int i = 0; i < branches.size(); ++i)
	{
		branches[i].setPosition(pos.x, i * 150.f);
	}

	for (int i = 0; i < logs.size(); ++i)
	{
		logs[i].setPosition(pos.x, 840.f);
	}
}

Sides Tree::UpdateBranches()
{
	for (int i = branchesSide.size() - 1; i > 0; --i)
	{
		branchesSide[i] = branchesSide[i - 1];
	}
	branchesSide[0] = (Sides)Utils::RandomRange(0, 3);

	for (int i = 0; i < branchesSide.size(); ++i)
	{
		switch (branchesSide[i])
		{
		case Sides::Left:
			branches[i].setScale(-1.f, 1.f);
			break;
		case Sides::Right:
			branches[i].setScale(1.f, 1.f);
			break;
		}
	}

	return branchesSide[0];
}

void Tree::UpdateLogSide(Sides side)
{
	logSide[logIndex] = side;
	logIndex = (logIndex + 1) % LOGCOUNT;

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	// PlaySlot으로 분기
	switch (slot)
	{
		case PlayerSlot::Single:
			logs[logIndex].setPosition(windowBounds.width * 0.5f, 840.f);
			break;
		case PlayerSlot::CoopPlayer1:
			logs[logIndex].setPosition(windowBounds.width * 0.25f, 840.f);
			break;
		case PlayerSlot::CoopPlayer2:
			logs[logIndex].setPosition(windowBounds.width * 0.75f, 840.f);
			break;
	}

	logSide[logIndex] = Sides::None;
}

void Tree::Init()
{
	texIdTree = "graphics/tree.png";
	texIdBranch = "graphics/branch.png";
	texIdLog = "graphics/log.png";

	branches.resize(6);
	branchesSide.resize(6);
	logs.resize(LOGCOUNT);
	logSide.resize(LOGCOUNT);

	logVec.resize(3);
	logVec[(int)Sides::Left] = { 2500.f , -500.f };
	logVec[(int)Sides::Right] = { -2500.f , -500.f };
	logVec[(int)Sides::None] = { 0.f, 0.f };
}

void Tree::Release()
{
}

void Tree::Reset()
{
	tree.setTexture(TEXTURE_MGR.Get(texIdTree), true);
	Utils::SetOrigin(tree, Origins::TC);

	sf::FloatRect bounds = tree.getLocalBounds();

	for (int i = 0; i < branches.size(); ++i)
	{
		branches[i].setTexture(TEXTURE_MGR.Get(texIdBranch));
		branches[i].setOrigin(bounds.width * -0.5f, 0.f);

		branchesSide[i] = (Sides)Utils::RandomRange(0, 3);

		switch (branchesSide[i])
		{
		case Sides::Left:
			branches[i].setScale(-1.f, 1.f);
			break;
		case Sides::Right:
			branches[i].setScale(1.f, 1.f);
			break;
		}
	}
	branchesSide[branches.size() - 1] = Sides::None;

	for (int i = 0; i < logs.size(); ++i)
	{
		logs[i].setTexture(TEXTURE_MGR.Get(texIdLog));
		Utils::SetOrigin(logs[i], Origins::MC);
		logSide[i] = Sides::None;
	}

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	// PlaySlot으로 분기
	switch (slot)
	{
		case PlayerSlot::Single:
			SetPosition({ windowBounds.width * 0.5f, 0.f });
			break;
		case PlayerSlot::CoopPlayer1:
			SetPosition({ windowBounds.width * 0.25f, 0.f });
			break;
		case PlayerSlot::CoopPlayer2:
			SetPosition({ windowBounds.width * 0.75f, 0.f });
			break;
	}
}

void Tree::Update(float dt)
{
	for (int i = 0; i < logs.size(); ++i)
	{
		sf::Vector2f pos = logs[i].getPosition();
		pos += logVec[(int)logSide[i]] * dt;
		logs[i].setPosition(pos);
	}
}

void Tree::Draw(sf::RenderWindow& window)
{
	window.draw(tree);

	for (int i = 0; i < branches.size(); ++i)
	{
		if (branchesSide[i] != Sides::None)
		{
			window.draw(branches[i]);
		}
	}

	for (int i = 0; i < logs.size(); ++i)
	{
		window.draw(logs[i]);
	}
}
