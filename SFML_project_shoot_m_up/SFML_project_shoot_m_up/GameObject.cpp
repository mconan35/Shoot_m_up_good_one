#include "GameObject.h"

GameObject::GameObject() : m_is_alive(true), m_speed(0), m_acceleration(0) {}

void GameObject::InitGameObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration) {
    m_position.SetPosition(position.x, position.y);
    m_bounds.SetRectangle(bounds.x, bounds.y, bounds.width, bounds.height);
    m_speed = speed;
    m_acceleration = acceleration;
    m_center = GetBounds().height / 2 + GetBounds().width / 2;
    m_is_alive = true;
}

void GameObject::Destroy() {
    m_is_alive = false;
}

bool GameObject::IsDestroy() {
    return !m_is_alive;
}

Rectangle2 GameObject::GetBounds()
{
    return m_bounds;
}

bool GameObject::IsColliding(GameObject* object)
{
    float distance_x = (object->m_position.x + object->GetBounds().x / 2) - (m_position.x + GetBounds().x / 2);
    float distance_y = (object->m_position.y + object->GetBounds().y / 2) - (m_position.y + GetBounds().y / 2);
    float distance_total = sqrt(distance_x* distance_x + distance_y* distance_y);
    return distance_total <= m_center + object->m_center;
}

void GameObject::SetGrouptTag(ObjectType type)
{
    m_group_tag = type;
}

int GameObject::GetGroupTag()
{
    return m_group_tag;
}
