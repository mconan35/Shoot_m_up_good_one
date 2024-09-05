#include "GameObject.h"

GameObject::GameObject() : m_is_alive(true), m_speed(0), m_acceleration(0) {}

void GameObject::InitGameObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration) {
    m_position.SetPosition(position.x, position.y);
    m_bounds.SetRectangle(bounds.x, bounds.y, bounds.width, bounds.height);
    m_speed = speed;
    m_acceleration = acceleration;
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
    if (this == object)
        return false;

    if (GetGroupTag() == object->GetGroupTag())
        return false;

    if ( m_bounds.y + m_bounds.height <= object->m_bounds.y )
        return false;

    if ( m_bounds.y >= object->m_bounds.y + object->m_bounds.height)
        return false;

    if (m_bounds.x + m_bounds.width <= object->m_bounds.x)
        return false;

    if (m_bounds.x >= object->m_bounds.x + object->m_bounds.width)
        return false;

    return true;
}

void GameObject::SetGrouptTag(ObjectType type)
{
    m_group_tag = type;
}

int GameObject::GetGroupTag()
{
    return m_group_tag;
}
