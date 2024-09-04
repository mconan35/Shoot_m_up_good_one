#pragma once
#include <SFML/Graphics.hpp>

class Player;

class Level
{
public :
	Level();
	
	void SpawnEnemies();
	void UpdateEntity();
	void CollisionManager();
	void Purge();
	void Update();

	virtual ~Level() = default;

protected:
	sf::RenderWindow* m_pWindow;
	float m_latest_time = 0.0f;
	int m_max_ennemies_nb = 10;
	int m_current_enemies_nb = 0;
	Player* player;

};
