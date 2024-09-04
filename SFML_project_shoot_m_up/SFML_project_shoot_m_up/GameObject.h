#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Rectangle.h"

enum ObjectType {
	PLAYER,
	PROJECTILE,
	ENEMY
};

class GameObject
{
public:
	GameObject();
	void InitGameObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration);

	void Destroy();
	bool IsDestroy();
	Rectangle2 GetBounds();
	bool IsColliding(GameObject* object);
	void SetGrouptTag(ObjectType type);
	int GetGroupTag();

	virtual void Update() = 0;
	virtual void DrawShape(sf::RenderWindow* window) = 0;
	virtual ObjectType GetType() = 0;


	virtual ~GameObject() = default;

protected:
	Vector2 m_position;
	Rectangle2 m_bounds;
	float m_speed;
	float m_acceleration;
	float m_center;
	bool m_is_alive;
	int m_group_tag;
};

