#pragma once
#include <Windows.h>

enum controlState {
	PUSHED = 1,
	UP,
	DOWN,
	NONE
};

class Controller
{
public:

	Controller();

	void UpdateController();
	bool IsKey(int key);
	bool IsKeyDown(int key);
	bool IsKeyNone(int key);

	virtual ~Controller() = default;

protected:
	BYTE m_keys_tab[255];
};

