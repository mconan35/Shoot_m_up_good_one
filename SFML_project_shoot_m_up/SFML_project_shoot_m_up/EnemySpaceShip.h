#pragma once
#include "SpaceShip.h"

class EnemySpaceShip : public SpaceShip
{
public:
	void DrawShape(sf::RenderWindow* window) override;
	void Update() override;

protected:
	sf::RectangleShape m_ennemy_shape;
};
