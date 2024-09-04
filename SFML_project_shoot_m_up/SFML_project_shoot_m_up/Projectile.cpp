#include "Projectile.h"
#include "Player.h"

Projectile::Projectile()
{
	m_group_tag = ObjectType::PLAYER;
}

void Projectile::DrawShape(sf::RenderWindow* window)
{
	if (m_is_alive) {
		m_projectile_shape.setSize(sf::Vector2f(5.f, 20.f));
		m_projectile_shape.setFillColor(sf::Color::White);
		m_projectile_shape.setPosition(m_position.x + m_bounds.width * 4.5, m_position.y);
		window->draw(m_projectile_shape);
	}
}

void Projectile::Update()
{
	m_speed += m_acceleration * GameManager::GetElapsedTime();
	if (m_speed >= 800.f) {
		m_speed = 800.f;
	}
	m_position.y -= m_speed * GameManager::GetElapsedTime();
	if (m_projectile_shape.getPoint(2).y < 0.f) {
		m_is_alive = false;
	}
	if (m_position.y < 0 || m_position.y > GameManager::GetWindow()->getSize().y) {
		m_is_alive = false;
	}
}

ObjectType Projectile::GetType()
{
	return ObjectType::PROJECTILE;
}
