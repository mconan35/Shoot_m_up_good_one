#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "Timer.h"
#include "Controller.h"
#include "Vector2.h"
#include "Rectangle.h"
#include "GameObject.h"

class Projectile;

class Player;

class GameManager
{
public:

	GameManager();

	void Run();
	void GlobalUpdate();
	void Render();
	void SpawnEnemies();
	static bool IsKeyNone(int key);
	static bool IsKeyDown(int key);
	static bool IsKeyPushed(int key);
	static float GetElapsedTime();
	static float GetTotalTime();
	static sf::RenderWindow* GetWindow();
	static GameManager* GetManagerInstance();
	template<class T> T* CreateObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration);

	virtual ~GameManager() = default;

	std::list<GameObject*> objects_list;

protected:
	sf::RenderWindow* m_pWindow;
	sf::RectangleShape m_shape;
	Timer m_generic_timer;
	Controller current_controller;
	Player* m_main_character;
	Vector2* m_base_position;
	Projectile* m_current_projectile;
	// Pour spawn d'ennemis
	float m_latest_time = 0.0f;
	int m_max_ennemies_nb = 5;
	int m_current_enemies_nb = 0;
};

template<class T> T* GameManager::CreateObject(Vector2 position, Rectangle2 bounds, float speed, float acceleration) {
	T* go = new T;
	go->InitGameObject(position, bounds, speed, acceleration);
	objects_list.push_back((GameObject*)go);
	return go;
}