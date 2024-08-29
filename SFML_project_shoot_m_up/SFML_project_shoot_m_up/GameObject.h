#pragma once
#include "Vector2.h"
#include "Rectangle.h"

class GameObject
{
public:
	GameObject();
	void InitGameObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration, bool is_alive);

	void Destroy();
	bool IsDestroy() const;

	virtual ~GameObject() = default;

protected:
	Vector2 m_position;
	Rectangle2 m_bounds;
	float m_speed;
	float m_acceleration;
	bool m_is_alive;
};

