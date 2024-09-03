#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Rectangle.h"

class GameObject
{
public:
	GameObject();
	void InitGameObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration);

	void Destroy();
	bool IsDestroy();

	virtual void Update() = 0;
	virtual void DrawShape(sf::RenderWindow* window) = 0;

	virtual ~GameObject() = default;

protected:
	Vector2 m_position;
	Rectangle2 m_bounds;
	float m_speed;
	float m_acceleration;
	bool m_is_alive;
};

