#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"

SceneGame::SceneGame() : Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    //

    AddGameObject(new SpriteGo("graphics/background.png"));
    
    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }

    tree = (Tree*)AddGameObject(new Tree());

    BackgroundElement* element = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));
    element->minScale = 1.f;
    element->maxScale = 1.f;
    element->minY = 600;
    element->maxY = 800;
    element->minSpeed = 400;
    element->maxSpeed = 600;
    element->SetMoveType(BackgroundElement::MoveType::Wave);

    player = (Player*)AddGameObject(new Player());

    uiHud = (UiHud*)AddGameObject(new UiHud());

    Scene::Init();
}

void SceneGame::Enter()
{
    Scene::Enter();

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;
    player->SetPosition(pos);

    score = 0;
    uiHud->SetScore(score);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::Update(float dt)
{
    Scene::Update(dt);

    if (isPlaying)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Left);
            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                FRAMEWORK.SetTimeScale(0.f);
                player->SetAlive(false);

                uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");
            }
            else
            {
                score += 10;
                uiHud->SetScore(score);
            }
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Right);
            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                FRAMEWORK.SetTimeScale(0.f);
                player->SetAlive(false);

                uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");
            }
            else
            {
                score += 10;
                uiHud->SetScore(score);
            }
        }

        player->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));
     
        timer -= dt;
        if (timer <= 0.f)
        {
            timer = 0.f;

            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);
            player->SetAlive(false);

            uiHud->SetShowMassage(true);
            uiHud->SetMessage("Enter to Restart!");
        }
        uiHud->SetTimeBar(timer / timerMax);
    }
    else
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player->Reset();
            tree->Reset();
            isPlaying = true;

            score = 0;
            uiHud->SetScore(score);

            timer = timerMax;
            uiHud->SetTimeBar(timer / timerMax);

            uiHud->SetShowMassage(false);
        }
    }

    
}
