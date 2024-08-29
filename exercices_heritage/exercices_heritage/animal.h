#pragma once
#include <iostream>
#include <cmath>

enum animal_type {
	shark = 1,
	eagle,
	swan
};

class Animal
{
public:
	Animal();

	static int s_id;

	virtual bool IsFish() = 0;
	virtual bool IsBird() = 0;
	virtual bool IsCarnivore() = 0;

	void SetWeight(int new_weight);
	void SetPositionY(int new_position_y);
	void InitAnimal(int weight, int position_y, animal_type type);
	void Die();
	void MoveToSea();
	int GetDistance(Animal& other_animal);
	bool CanEat(Animal& prey);
	void Eat(Animal& prey);

	virtual ~Animal() = default;

protected:
	int m_id;
	int m_weight;
	int m_position_y;
	bool m_is_alive;
	animal_type m_at;
};

