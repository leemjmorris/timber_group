#pragma once

class SoundMgr
{
private:
	static sf::Sound soundChop;
	static sf::Sound soundDeath;
	static sf::Sound soundOutTime;

public:
	static void Init();
	static void Clear();

	static void PlayChop();
	static void PlayDeath();
	static void PlayOutTime();
};

