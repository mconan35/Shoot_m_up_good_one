#pragma once
#include "SpaceShip.h"
#include "GameManager.h"

class Projectile : public GameObject
{
public:
	Projectile();

	void DrawShape(sf::RenderWindow* window) override;
	void Update() override;
	ObjectType GetType() override;

protected:
	sf::RectangleShape m_projectile_shape;
	Player* m_player;
};
