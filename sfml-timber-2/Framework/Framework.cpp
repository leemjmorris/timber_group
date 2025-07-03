#include "stdafx.h"
#include "Framework.h"

void Framework::Init(int w, int h, const std::string& t)
{
	window.create(sf::VideoMode(w, h), t);

    // texIds, fontIds, soundIds
    soundIds.push_back("sound/chop.wav");
    soundIds.push_back("sound/death.wav");
    soundIds.push_back("sound/out_of_time.wav");
    soundIds.push_back("sound/intro_music.mp3");
    soundIds.push_back("sound/player1_select.wav");
    soundIds.push_back("sound/player2_select.wav");
    soundIds.push_back("sound/mode_select.wav");
    soundIds.push_back("sound/char_select.wav");
    soundIds.push_back("sound/game_play.wav");

	TEXTURE_MGR.Load(texIds);
	FONT_MGR.Load(fontIds);
	SOUNDBUFFER_MGR.Load(soundIds);

	InputMgr::Init();
    SoundMgr::Init();
	SCENE_MGR.Init();
}

void Framework::Do()
{
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        realDeltaTime = deltaTime = dt.asSeconds();
        deltaTime *= timeScale;
        time += deltaTime;
        realTime = realDeltaTime;

        InputMgr::Clear();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            InputMgr::UpdateEvent(event);
        }

        InputMgr::Update(deltaTime);

        // Update
        SCENE_MGR.Update(deltaTime);

        // Draw
        window.clear();
        SCENE_MGR.Draw(window);
        window.display();
    }
}

void Framework::Release()
{
	SCENE_MGR.Release();

	SOUNDBUFFER_MGR.Unload(soundIds);
	FONT_MGR.Unload(fontIds);
	TEXTURE_MGR.Unload(texIds);
}
