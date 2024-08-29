#include <iostream>
#include "animal.h"
#include "shark.h"
#include "eagle.h"
#include "swan.h"
int Animal::s_id;

int main() {
	Animal::s_id = 0;
	Animal* shark1 = new Shark();
	shark1->InitAnimal(1, -5, shark);
	Animal* shark2 = new Shark();
	shark2->InitAnimal(1, -5, shark);
	Animal* eagle1 = new Eagle();
	eagle1->InitAnimal(1, -10, eagle);
	Animal* eagle2 = new Eagle();
	eagle2->InitAnimal(1, -10, eagle);
	Animal* swan1 = new Swan();
	swan1->InitAnimal(1, -10, swan);
	Animal* swan2 = new Swan();
	swan2->InitAnimal(1, -10, swan);

	std::cout << "Test 1 : V�rifie la condition IsCarnivore" << std::endl;
	swan1->Eat(*eagle1);

	std::cout << "Test 2 : V�rifie la condition de ne pas se manger soi-m�me" << std::endl;
	shark1->Eat(*shark1);
	
	std::cout << "Test 3 : V�rifie la distance entre deux animaux" << std::endl;
	shark1->Eat(*swan1);
	
	std::cout << "Test 4 : V�rification comportement normal" << std::endl;
	shark1->MoveToSea();
	swan1->MoveToSea();
	shark1->Eat(*swan1);
	
	std::cout << "Test 5 : V�rifie la condition de proie morte/d�j� mang�e" << std::endl;
	shark1->Eat(*swan1);
		
	std::cout << "Test 6 : V�rification pr�dateur plus petit/l�ger ne peut pas manger proie plus grande/lourde" << std::endl;
	eagle2->Eat(*shark1);

	std::cout << "Test 7 : V�rification comportement normal" << std::endl;
	eagle2->MoveToSea();
	shark1->Eat(*eagle2);

	std::cout << "Test 8 : V�rification comportement normal" << std::endl;
	eagle1->Eat(*swan2);

	return 0;
}