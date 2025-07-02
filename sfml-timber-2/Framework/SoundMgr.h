#pragma once

class SoundMgr
{
private:
	static sf::Sound soundChop;
	static sf::Sound soundDeath;
	static sf::Sound soundOutTime;

public:
	static sf::Sound soundIntro;
	static sf::Sound soundP1Select;
	static sf::Sound soundP2Select;

	static void Init();
	static void Clear();

	static void PlayChop();
	static void PlayDeath();
	static void PlayOutTime();
};

