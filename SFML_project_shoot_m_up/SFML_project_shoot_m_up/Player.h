#pragma once
#include "SpaceShip.h"
#include "GameManager.h"
#include "Projectile.h"

class Player : public SpaceShip
{
public:
	void InitPlayer(Vector2 position, Rectangle2 bounds, float speed, float acceleration);
	void DrawShape(sf::RenderWindow* window) override;
	void Shoot();
	void Move(int direction);
	void Update() override;

protected:
	sf::RectangleShape m_player_shape;
	Projectile* m_projectile_player;
	float m_latest_time = 0.f;
};
