#include "stdafx.h"
#include "SoundMgr.h"

sf::Sound SoundMgr::soundChop;
sf::Sound SoundMgr::soundDeath;
sf::Sound SoundMgr::soundOutTime;

void SoundMgr::Init()
{
    soundChop.setBuffer(SOUNDBUFFER_MGR.Get("sound/chop.wav"));
    soundDeath.setBuffer(SOUNDBUFFER_MGR.Get("sound/death.wav"));
    soundOutTime.setBuffer(SOUNDBUFFER_MGR.Get("sound/out_of_time.wav"));
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

