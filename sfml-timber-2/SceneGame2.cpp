#include "stdafx.h"
#include "SceneGame2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "SceneChar.h"

SceneGame2::SceneGame2()
    : Scene(SceneIds::Game)
{
}

SceneGame2::~SceneGame2()
{
}

void SceneGame2::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/aura.png");
    texIds.push_back("graphics/log.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    //

    AddGameObject(new SpriteGo("graphics/background.png"));
    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }
    BackgroundElement* element = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));
    element->minScale = 1.f;
    element->maxScale = 1.f;
    element->minY = 600;
    element->maxY = 800;
    element->minSpeed = 400;
    element->maxSpeed = 600;
    element->SetMoveType(BackgroundElement::MoveType::Wave);

    tree1 = (Tree*)AddGameObject(new Tree());    
    player1 = (Player*)AddGameObject(new Player());
    tree2 = (Tree*)AddGameObject(new Tree());
    player2 = (Player*)AddGameObject(new Player());
    uiHud1 = (UiHud*)AddGameObject(new UiHud());
    uiHud2 = (UiHud*)AddGameObject(new UiHud());

    tree1->SetPlaySlot(PlayerSlot::CoopPlayer1);
    player1->SetPlaySlot(PlayerSlot::CoopPlayer1);
    uiHud1->SetPlaySlot(PlayerSlot::CoopPlayer1);
    tree2->SetPlaySlot(PlayerSlot::CoopPlayer2);
    player2->SetPlaySlot(PlayerSlot::CoopPlayer2);
    uiHud2->SetPlaySlot(PlayerSlot::CoopPlayer2);

    Scene::Init();
}

void SceneGame2::Enter()
{
    Scene::Enter();

    sf::Vector2f pos1 = tree1->GetPosition();
    pos1.y = 900.f;
    player1->SetPosition(pos1);
    sf::Vector2f pos2 = tree2->GetPosition();
    pos2.y = 900.f;
    player2->SetPosition(pos2);

    score1 = 0;
    score2 = 0;
    uiHud1->SetScore(score1);
    uiHud2->SetScore(score2);

    timer1 = timerMax;
    uiHud1->SetTimeBar(timer1 / timerMax);
    uiHud2->SetTimeBar(timer1 / timerMax);

    uiHud1->SetShowMassage(true);
    uiHud1->SetMessage("Enter to Start!");
    uiHud2->SetShowMassage(false);
}

void SceneGame2::Exit()
{
    Scene::Exit();
}

void SceneGame2::Update(float dt)
{
    Scene::Update(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
    {
        SCENE_MGR.ChangeScene(SceneIds::Mode);  // 선택 씬으로 전환
    }

    if (isPlaying)
    {
        PlayerOneKeyInput();
        PlayerTwoKeyInput();

        player1->SetDrawAxe(InputMgr::GetKey(sf::Keyboard::A) || InputMgr::GetKey(sf::Keyboard::D));
        player2->SetDrawAxe(InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));

        PlayerOneCrashCheck();
        PlayerTwoCrashCheck();      

        if (score1 >= feverScore1)
        {
            isFever1 = true;
            fevertimer1 = 0.f;
            player1->SetDrawAura(true);
            feverScore1 *= 2;
        }

        if (score2 >= feverScore2)
        {
            isFever2 = true;
            fevertimer2 = 0.f;
            player2->SetDrawAura(true);
            feverScore2 *= 2;
        }

        TimerUpdate(dt);
        FeverTimerUpdate(dt);
    }
    else
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            Restart();
        }
    }
}

void SceneGame2::PlayerOneKeyInput()
{
    if (InputMgr::GetKeyDown(sf::Keyboard::A))
    {
        tree1->UpdateBranches();
        tree1->UpdateLogSide(Sides::Left);
        player1->SetSide(Sides::Left);        
        score1 += isFever1 ? 20 : 10;
        uiHud1->SetScore(score1);
        SoundMgr::PlayChop();
    }

    if (InputMgr::GetKeyDown(sf::Keyboard::D))
    {
        tree1->UpdateBranches();
        tree1->UpdateLogSide(Sides::Right);
        player1->SetSide(Sides::Right);
        score1 += isFever1 ? 20 : 10;
        uiHud1->SetScore(score1);
        SoundMgr::PlayChop();
    }
}

void SceneGame2::PlayerTwoKeyInput()
{
    if (InputMgr::GetKeyDown(sf::Keyboard::Left))
    {
        tree2->UpdateBranches();
        tree2->UpdateLogSide(Sides::Left);
        player2->SetSide(Sides::Left);
        score2 += isFever2 ? 20 : 10;
        uiHud2->SetScore(score2);
        SoundMgr::PlayChop();
    }

    if (InputMgr::GetKeyDown(sf::Keyboard::Right))
    {
        tree2->UpdateBranches();
        tree2->UpdateLogSide(Sides::Right);
        player2->SetSide(Sides::Right);
        score2 += isFever2 ? 20 : 10;
        uiHud2->SetScore(score2);
        SoundMgr::PlayChop();
    }
}

void SceneGame2::PlayerOneCrashCheck()
{
    if (tree1->GetSide() == player1->GetSide())
    {
        isPlaying = false;
        FRAMEWORK.SetTimeScale(0.f);
        player1->SetAlive(false);

        uiHud1->SetShowMassage(true);
        uiHud1->SetMessage("Player 2 Win!");
        SoundMgr::PlayDeath();
    }
}

void SceneGame2::PlayerTwoCrashCheck()
{
    if (tree2->GetSide() == player2->GetSide())
    {
        isPlaying = false;
        FRAMEWORK.SetTimeScale(0.f);
        player2->SetAlive(false);

        uiHud1->SetShowMassage(true);
        uiHud1->SetMessage("Player 1 Win!");
        SoundMgr::PlayDeath();
    }
}

void SceneGame2::TimerUpdate(float dt)
{
    timer1 -= dt;
    if (timer1 <= 0.f)
    {
        timer1 = 0.f;

        isPlaying = false;
        FRAMEWORK.SetTimeScale(0.f);
        player1->SetAlive(false);
        player2->SetAlive(false);

        uiHud1->SetShowMassage(true);
        if (score1 > score2)
        {
            uiHud1->SetMessage("Player1 Win!");
        }
        else if (score1 < score2)
        {
            uiHud1->SetMessage("Player2 Win!");
        }
        else
        {
            uiHud1->SetMessage("Draw!");
        }
        SoundMgr::PlayOutTime();
    }
    uiHud1->SetTimeBar(timer1 / timerMax);
    uiHud2->SetTimeBar(timer1 / timerMax);    
}

void SceneGame2::FeverTimerUpdate(float dt)
{
    if (isFever1)
    {
        fevertimer1 += dt;
        if (fevertimer1 >= fevertime)
        {
            fevertimer1 = 0;
            isFever1 = false;
            player1->SetDrawAura(false);
        }
    }

    if (isFever2)
    {
        fevertimer2 += dt;
        if (fevertimer2 >= fevertime)
        {
            fevertimer2 = 0;
            isFever2 = false;
            player2->SetDrawAura(false);
        }
    }
}

void SceneGame2::Restart()
{
    FRAMEWORK.SetTimeScale(1.f);
    player1->Reset();
    tree1->Reset();
    player2->Reset();
    tree2->Reset();
    isPlaying = true;

    score1 = 0;
    uiHud1->SetScore(score1);
    score2 = 0;
    uiHud2->SetScore(score2);

    timer1 = timerMax;
    uiHud1->SetTimeBar(timer1 / timerMax);
    uiHud2->SetTimeBar(timer1 / timerMax);
    uiHud1->SetShowMassage(false);

    feverScore1 = BASESCORE;
    feverScore2 = BASESCORE;
    fevertimer1 = 0.f;
    fevertimer2 = 0.f;
    isFever1 = false;
    isFever2 = false;
}
