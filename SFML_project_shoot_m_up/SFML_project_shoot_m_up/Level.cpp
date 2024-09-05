#include "Level.h"
#include "GameManager.h"
#include "EnemySpaceShip.h"
#include"Windows.h"

Level::Level()
{
}

void Level::SpawnEnemies()
{
    if ((GameManager::GetManagerInstance()->GetTotalTime() - m_latest_time) > 3.0f && m_current_enemies_nb < m_max_ennemies_nb) {
        m_latest_time = GameManager::GetManagerInstance()->GetTotalTime();
        m_pWindow = GameManager::GetManagerInstance()->GetWindow();
        Vector2 enemy_position(
            std::max(0.0f, static_cast<float>(std::rand() % (m_pWindow->getSize().x - 50))),
            std::rand() % (m_pWindow->getSize().y / 2)
        );
        Rectangle2 projectile_bounds(enemy_position.x-50.0f, enemy_position.y-50.0f, 50.f, 50.f);
        EnemySpaceShip* new_enemy = GameManager::GetManagerInstance()->CreateObject<EnemySpaceShip>(enemy_position, projectile_bounds, 0.f, 0.f);
        m_current_enemies_nb++;
    }
}

void Level::UpdateEntity()
{
    for (auto iterator = GameManager::GetObjectList().begin(); iterator != GameManager::GetObjectList().end(); iterator++) {
        GameObject* object = *iterator;
        object->Update();
    }
}

void Level::CollisionManager()
{
    for (auto iterator = GameManager::GetObjectList().begin(); iterator != GameManager::GetObjectList().end(); ++iterator) {
        GameObject* object = *iterator;
        for (auto other_iterator = GameManager::GetObjectList().begin(); other_iterator != GameManager::GetObjectList().end(); ++other_iterator) {
            GameObject* other_object = *other_iterator;            
            OutputDebugStringA("Avant IF\r\n");
            if (object->IsColliding(other_object))
            {
                OutputDebugStringA("Après\r\n");
                object->Destroy();
                other_object->Destroy();
                OutputDebugStringA("FIN IF\r\n");
            }
        }
    }
}

void Level::Purge()
{
    for (auto iterator = GameManager::GetObjectList().begin(); iterator != GameManager::GetObjectList().end(); ) {
        GameObject* object = *iterator;
        if (object->IsDestroy()) {
            delete object;
            iterator = GameManager::GetObjectList().erase(iterator);
            /*if (object->GetType() == ObjectType::ENEMY) {
                m_current_enemies_nb--;
            }*/
            continue;
        }
        ++iterator;
    }
}

void Level::Update()
{
    srand(timeGetTime());
    SpawnEnemies();
    UpdateEntity();
    CollisionManager();
    Purge();
}