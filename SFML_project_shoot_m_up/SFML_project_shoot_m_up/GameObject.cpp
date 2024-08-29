#include "GameObject.h"

GameObject::GameObject() : m_is_alive(true), m_speed(0), m_acceleration(0) {}

void GameObject::InitGameObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration, bool is_alive) {
    m_position.SetPosition(position.x, position.y);
    m_bounds.SetRectangle(bounds.x, bounds.y, bounds.width, bounds.height);
    m_speed = speed;
    m_acceleration = acceleration;
    m_is_alive = is_alive;
}

void GameObject::Destroy() {
    m_is_alive = false;
}

bool GameObject::IsDestroy() const {
    return !m_is_alive;
}
