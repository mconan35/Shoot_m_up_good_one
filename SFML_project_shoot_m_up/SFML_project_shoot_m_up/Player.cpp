#include "Player.h"

void Player::CreatePlayer(Vector2 position, Rectangle2 bounds, float speed, float acceleration)
{
	m_position = position;
	m_bounds = bounds;
	m_speed = speed;
	m_acceleration = acceleration;
}

void Player::DrawShape()
{
	m_shape.setSize(sf::Vector2f(m_bounds.x, m_bounds.y));
	m_shape.setFillColor(sf::Color::Cyan);
	m_shape.setPosition(sf::Vector2f(400 - (m_position.x)/2, 800 - m_position.y));
	// faire calculs compliqués dans GameManager ou faire un initPlayer propre.
}

sf::RectangleShape Player::GetShape()
{
	return m_shape;
}

void Player::UpdatePlayer()
{
	if (GameManager::IsKeyPushed('D')) {
		Move(1);
	}
	else if (GameManager::IsKeyPushed('Q')) {
		Move(-1);
	}
	else if (GameManager::IsKeyNone('D')) {
		m_speed = 100.f;
	}
	else if (GameManager::IsKeyNone('Q')) {
		m_speed = 100.f;
	}
}

void Player::Move(int direction)
{
	m_speed += m_acceleration * GameManager::GetElapsedTime();
	if (m_speed >= 500.f) {
		m_speed = 500.f;
	}
	m_position.x += m_speed * direction * GameManager::GetElapsedTime();
	if (m_position.x < 0) {
		m_position.x = 0;
	}
	else if (m_position.x > GameManager::GetWindow()->getSize().x - 100.f) {
		m_position.x = GameManager::GetWindow()->getSize().x - 100.f;
	}
}
