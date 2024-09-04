#pragma once
#include "SpaceShip.h"

class EnemySpaceShip : public SpaceShip
{
public:
	EnemySpaceShip();

	void DrawShape(sf::RenderWindow* window) override;
	void Update() override;
	ObjectType GetType() override;

protected:
	sf::RectangleShape m_ennemy_shape;
};
