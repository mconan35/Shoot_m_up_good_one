#include "GameManager.h"
#include "Player.h"
#include "Projectile.h"
#include "EnemySpaceShip.h"

GameManager::GameManager()
{
}

void GameManager::Run()
{
    Vector2* m_base_position = new Vector2(100.f, 100.f);
    Vector2* relative_position = new Vector2(400.f - (m_base_position->x) / 2, 800.f - m_base_position->y);
    m_pWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML wooorks!");
    m_main_character = new Player;
    m_main_character->InitPlayer(*relative_position, Rectangle2(m_base_position->x, m_base_position->y, 50.f, 75.f), 50.f, 400.f);
    objects_list.push_back(m_main_character);
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
    delete m_base_position;
    m_base_position = nullptr;
    delete relative_position;
    relative_position = nullptr;
}

void GameManager::GlobalUpdate()
{
    m_generic_timer.UpdateTime();
    m_current_controller.UpdateController();
    m_current_level.Update();
}

void GameManager::Render()
{
    m_pWindow->clear();
    for (auto game_object : objects_list)
    {
        game_object->DrawShape(m_pWindow);
    }
    m_pWindow->display();
}

bool GameManager::IsKeyNone(int key)
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->m_current_controller.IsKeyNone(key);
}

bool GameManager::IsKeyDown(int key)
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->m_current_controller.IsKeyDown(key);
}

bool GameManager::IsKeyPushed(int key)
{
    GameManager* main_game = GameManager::GetManagerInstance();
    return main_game->m_current_controller.IsKey(key);
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

std::list<GameObject*>& GameManager::GetObjectList()
{
    GameManager* temp_manager = GameManager::GetManagerInstance();
    return temp_manager->objects_list;
}
