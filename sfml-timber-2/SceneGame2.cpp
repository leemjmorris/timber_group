#include "stdafx.h"
#include "SceneGame2.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"

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

    // 수정하기
    tree1 = (Tree*)AddGameObject(new Tree());
    player1 = (Player*)AddGameObject(new Player());
    uiHud1 = (UiHud*)AddGameObject(new UiHud());
    tree2 = (Tree*)AddGameObject(new Tree());
    player2 = (Player*)AddGameObject(new Player());
    uiHud2 = (UiHud*)AddGameObject(new UiHud());

    Scene::Init();
}

void SceneGame2::Enter()
{
    Scene::Enter();

    // 수정하기
    sf::Vector2f pos = tree1->GetPosition();
    pos.y = 950.f;
    player1->SetPosition(pos);

    score1 = 0;
    uiHud1->SetScore(score1);

    timer1 = timerMax;
    uiHud1->SetTimeBar(timer1 / timerMax);

    uiHud1->SetShowMassage(true);
    uiHud1->SetMessage("Enter to Start!");
}

void SceneGame2::Exit()
{
    Scene::Exit();
}

void SceneGame2::Update(float dt)
{
    Scene::Update(dt);

    // 수정하기
    if (isPlaying)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree1->UpdateBranches();
            tree1->UpdateLogSide(Sides::Left);
            player1->SetSide(Sides::Left);
            score1 += 10;
            uiHud1->SetScore(score1);
            SoundMgr::PlayChop();
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            tree1->UpdateBranches();
            tree1->UpdateLogSide(Sides::Right);
            player1->SetSide(Sides::Right);
            score1 += 10;
            uiHud1->SetScore(score1);
            SoundMgr::PlayChop();
        }

        player1->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));

        if (tree1->GetSide() == player1->GetSide())
        {
            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);
            player1->SetAlive(false);

            uiHud1->SetShowMassage(true);
            uiHud1->SetMessage("Enter to Restart!");
            SoundMgr::PlayDeath();
        }

        timer1 -= dt;
        if (timer1 <= 0.f)
        {
            timer1 = 0.f;

            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);
            player1->SetAlive(false);

            uiHud1->SetShowMassage(true);
            uiHud1->SetMessage("Enter to Restart!");
            SoundMgr::PlayOutTime();
        }
        uiHud1->SetTimeBar(timer1 / timerMax);
    }
    else
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player1->Reset();
            tree1->Reset();
            isPlaying = true;

            score1 = 0;
            uiHud1->SetScore(score1);

            timer1 = timerMax;
            uiHud1->SetTimeBar(timer1 / timerMax);

            uiHud1->SetShowMassage(false);
        }
    }
}
