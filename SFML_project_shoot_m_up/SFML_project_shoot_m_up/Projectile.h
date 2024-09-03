#pragma once
#include "SpaceShip.h"
#include "GameManager.h"

class Projectile : public GameObject
{
public:
	void DrawShape(sf::RenderWindow* window) override;
	void Update() override;

protected:
	sf::RectangleShape m_projectile_shape;
	Player* m_player;
};
