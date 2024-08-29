#include <iostream>
#include "Controller.h"

Controller::Controller() {
	for (int i = 0; i < 255; i++) {
		m_keys_tab[i] = controlState::NONE;
	}
}

void Controller::UpdateController() {
	for (int i = 0; i < 255; i++) {
		bool temp_key = GetAsyncKeyState(i) < 0;
		if (temp_key) {
			switch (m_keys_tab[i]) {
			case controlState::NONE:
				m_keys_tab[i] = controlState::DOWN;
				std::cout << "down" << std::endl;
			case controlState::DOWN:
				m_keys_tab[i] = controlState::PUSHED;
				std::cout << "pushed" << std::endl;
			case controlState::UP:
				m_keys_tab[i] = controlState::DOWN;
				std::cout << "down" << std::endl;
			case controlState::PUSHED:
				m_keys_tab[i] = controlState::PUSHED;
				std::cout << "pushed" << std::endl;
			}
		}
		else {
			switch (m_keys_tab[i]) {
			case controlState::PUSHED:
				m_keys_tab[i] = controlState::UP;
				std::cout << "up" << std::endl;
			case controlState::DOWN:
				m_keys_tab[i] = controlState::UP;
				std::cout << "up" << std::endl;
			case controlState::UP:
				m_keys_tab[i] = controlState::NONE;
				std::cout << "none" << std::endl;
			}
		}
	}
}

bool Controller::IsKey(int key)
{
	return m_keys_tab[key] == controlState::DOWN || m_keys_tab[key] == controlState::PUSHED;
}

bool Controller::IsKeyDown(int key)
{
	return m_keys_tab[key] == controlState::DOWN;
}

bool Controller::IsKeyNone(int key)
{
	return m_keys_tab[key] == controlState::NONE;
}
