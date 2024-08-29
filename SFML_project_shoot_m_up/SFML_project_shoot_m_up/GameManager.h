#pragma once
#include "SFML/Graphics.hpp"
#include "Timer.h"
#include "Controller.h"

class Player;

class GameManager
{
public:

	GameManager();

	void Run();
	void GlobalUpdate();
	void Render();
	static bool IsKeyNone(int key);
	static bool IsKeyDown(int key);
	static bool IsKeyPushed(int key);
	static float GetElapsedTime();
	static float GetTotalTime();
	static sf::RenderWindow* GetWindow();
	static GameManager* GetManagerInstance();

	virtual ~GameManager() = default;

protected:
	sf::RenderWindow* m_pWindow;
	sf::RectangleShape m_shape;
	Timer m_generic_timer;
	Controller current_controller;
	Player* m_main_character;
};

