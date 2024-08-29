#include "GameManager.h"
#include "Player.h"

GameManager::GameManager()
{
    m_pWindow = nullptr;
    m_main_character = nullptr;
}

void GameManager::Run()
{
    m_pWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML wooorks!");
    m_main_character = new Player;
    m_main_character->CreatePlayer(Vector2(100.f, 100.f), Rectangle2(100.f, 100.f, 50.f, 75.f), 200.f, 100.f);
    while (m_pWindow->isOpen())
    {
        sf::Event event;
        while (m_pWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_pWindow->close();
        }
        GlobalUpdate();
        Render();
    }
    delete m_pWindow;
    m_pWindow = nullptr;
}

void GameManager::GlobalUpdate()
{
    m_generic_timer.UpdateTime();
    current_controller.UpdateController();
    m_main_character->UpdatePlayer();
}

void GameManager::Render()
{
    m_pWindow->clear();
    m_main_character->DrawShape();
    m_pWindow->draw(m_main_character->GetShape());
    m_pWindow->display();
}

bool GameManager::IsKeyNone(int key)
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->current_controller.IsKeyNone(key);
}

bool GameManager::IsKeyDown(int key)
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->current_controller.IsKeyDown(key);
}

bool GameManager::IsKeyPushed(int key)
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->current_controller.IsKey(key);
}

float GameManager::GetElapsedTime()
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->m_generic_timer.GetElapsedTime();
}

float GameManager::GetTotalTime()
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->m_generic_timer.GetTotalTime();
}

sf::RenderWindow* GameManager::GetWindow()
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->m_pWindow;
}

GameManager* GameManager::GetManagerInstance()
{
    static GameManager game_manager;
    return &game_manager;
}
