#include "EnemySpaceShip.h"
#include "GameManager.h"

void EnemySpaceShip::DrawShape(sf::RenderWindow* window)
{
	m_ennemy_shape.setSize(sf::Vector2f(75.f, 75.f));
	m_ennemy_shape.setFillColor(sf::Color::Magenta);
	m_ennemy_shape.setPosition(100.f, 100.f);
	window->draw(m_ennemy_shape);
}

void EnemySpaceShip::Update()
{
	GameManager::GetManagerInstance()->SpawnEnemies();
}
