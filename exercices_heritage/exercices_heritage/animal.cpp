#include <iostream>
#include "animal.h"

Animal::Animal() {
	m_weight = 0;
	m_position_y = 0;
	m_is_alive = true;
	s_id++;
	m_id = s_id;
}


void Animal::SetWeight(int new_weight) {
	m_weight = new_weight;
}

void Animal::SetPositionY(int new_position_y) {
	m_position_y = new_position_y;
}

void Animal::InitAnimal(int weight, int position_y, animal_type type) {
	SetWeight(weight);
	SetPositionY(position_y);
	m_at = type;
}

void Animal::Die() {
	m_is_alive = false;
}

void Animal::MoveToSea() {
	m_position_y = 0;
}

int Animal::GetDistance(Animal& animal) {
	return m_position_y - animal.m_position_y;
}

bool Animal::CanEat(Animal& prey) {

	if (m_id == prey.m_id) {
			std::cout << "Cet animal ne peut pas se manger lui-même !" << std::endl;
			return false;
	}
	else if (IsCarnivore() == false) {
		std::cout << "Cet animal n'est pas carnivore !" << std::endl;
		return false;
	}
	else if (prey.m_is_alive != true) {
		std::cout << "Cette proie a déjà été mangée !" << std::endl;
		return false;
	}
	else if (m_weight < prey.m_weight) {
		std::cout << "Cet animal ne peut pas manger une proie plus grosse que lui !" << std::endl;
		return false;
	}
	else if (GetDistance(prey) != 0) {
		std::cout << "Cet animal n'est pas assez proche de sa proie !" << std::endl;
		return false;
	}
	return true;
}

void Animal::Eat(Animal& prey) {
	if (CanEat(prey) == true) {
		m_weight += prey.m_weight;
		prey.Die();
		std::cout << "L'animal " << m_id << ", a mangé l'animal " << prey.m_id << "!" << std::endl;
	}
}
