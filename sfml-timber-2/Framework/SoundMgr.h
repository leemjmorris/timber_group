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
	static sf::Sound soundModeSelect;
	static sf::Sound soundCharSelect;
	static sf::Sound soundGamePlay;

	static void Init();
	static void Clear();

	static void PlayChop();
	static void PlayDeath();
	static void PlayOutTime();
};

