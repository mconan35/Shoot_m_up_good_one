#pragma once
#include "SpaceShip.h"
#include "GameManager.h"

class Player : public SpaceShip
{
public:
	void CreatePlayer(Vector2 position, Rectangle2 bounds, float speed, float acceleration);
	sf::RectangleShape GetShape();
	void DrawShape();
	void Move(int direction);
	void UpdatePlayer();

protected:
	sf::RectangleShape m_shape;
};
