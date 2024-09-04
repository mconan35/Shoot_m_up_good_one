#include "Player.h"
#include "GameManager.h"

Player::Player()
{
	m_group_tag = ObjectType::PLAYER;
}

void Player::InitPlayer(Vector2 position, Rectangle2 bounds, float speed, float acceleration)
{
	m_position = position;
	m_bounds = bounds;
	m_speed = speed;
	m_acceleration = acceleration;
}

void Player::DrawShape(sf::RenderWindow* window)
{
	if (m_is_alive) {
		m_player_shape.setSize(sf::Vector2f(m_bounds.x, m_bounds.y));
		m_player_shape.setFillColor(sf::Color::Cyan);
		m_player_shape.setPosition(sf::Vector2f(m_position.x, m_position.y));
		window->draw(m_player_shape);
	}
}

void Player::Shoot()
{
	GameManager* temp_manager = GameManager::GetManagerInstance();
	Vector2 projectile_position(m_position.x + (m_bounds.width / 2), m_position.y);
	Rectangle2 projectile_bounds(projectile_position.x, projectile_position.y, 5.f, 20.f);
	Projectile* new_projectile = temp_manager->CreateObject<Projectile>(projectile_position, projectile_bounds, 200.f, 100.f);
}

void Player::Update()
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
	if (GameManager::IsKeyPushed('M')) {
		if (GameManager::GetManagerInstance()->GetTotalTime() - m_latest_time > .20f) {
			Shoot();
			m_latest_time = GameManager::GetManagerInstance()->GetTotalTime();
		}
	}
	
}

ObjectType Player::GetType()
{
	return ObjectType::PLAYER;
}

void Player::Move(int direction)
{
	m_speed += m_acceleration * GameManager::GetElapsedTime();
	if (m_speed >= 600.f) {
		m_speed = 600.f;
	}
	m_position.x += m_speed * direction * GameManager::GetElapsedTime();
	if (m_position.x < 0) {
		m_position.x = 0;
	}
	else if (m_position.x > GameManager::GetWindow()->getSize().x - m_bounds.x) {
		m_position.x = GameManager::GetWindow()->getSize().x - m_bounds.x;
	}
}
