#include "Projectile.h"
#include "Player.h"

void Projectile::DrawShape(sf::RenderWindow* window)
{
	m_projectile_shape.setSize(sf::Vector2f(5.f, 20.f));
	m_projectile_shape.setFillColor(sf::Color::White);
	m_projectile_shape.setPosition(m_position.x + m_bounds.width*4.5, m_position.y);
	window->draw(m_projectile_shape);
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
}
