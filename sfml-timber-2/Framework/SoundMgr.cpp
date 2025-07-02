#include "stdafx.h"
#include "SoundMgr.h"

sf::Sound SoundMgr::soundChop;
sf::Sound SoundMgr::soundDeath;
sf::Sound SoundMgr::soundOutTime;
sf::Sound SoundMgr::soundIntro;
sf::Sound SoundMgr::soundP1Select;
sf::Sound SoundMgr::soundP2Select;

void SoundMgr::Init()
{
    soundChop.setBuffer(SOUNDBUFFER_MGR.Get("sound/chop.wav"));
    soundDeath.setBuffer(SOUNDBUFFER_MGR.Get("sound/death.wav"));
    soundOutTime.setBuffer(SOUNDBUFFER_MGR.Get("sound/out_of_time.wav"));
    soundIntro.setBuffer(SOUNDBUFFER_MGR.Get("sound/intro_music.mp3"));
    soundP1Select.setBuffer(SOUNDBUFFER_MGR.Get("sound/player1_select.wav"));
    soundP2Select.setBuffer(SOUNDBUFFER_MGR.Get("sound/player2_select.wav"));
}

void SoundMgr::Clear()
{

}

void SoundMgr::PlayChop()
{
    soundChop.play();
}

void SoundMgr::PlayDeath()
{
    soundDeath.play();
}

void SoundMgr::PlayOutTime()
{
    soundOutTime.play();
}
