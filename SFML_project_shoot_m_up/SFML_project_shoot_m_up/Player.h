#pragma once
#include "SpaceShip.h"
#include "GameManager.h"
#include "Projectile.h"

class Player : public SpaceShip
{
public:
	Player();

	void InitPlayer(Vector2 position, Rectangle2 bounds, float speed, float acceleration);
	void DrawShape(sf::RenderWindow* window) override;
	void Shoot();
	void MoveX(int direction);
	void MoveY(int direction);
	void Update() override;
	ObjectType GetType() override;


protected:
	sf::RectangleShape m_player_shape;
	Projectile* m_projectile_player;
	float m_latest_time = 0.f;
};
