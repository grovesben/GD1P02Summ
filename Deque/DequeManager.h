#pragma once
#include "Deque.h"
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <limits>
#include <vector>

class CDequeManager
{
public:
	CDequeManager();
	~CDequeManager();

	int Run();
	void Menu();
	int Input();

private:
	bool m_ProgramRunning;
	int m_Input;
	CDeque* m_pDeque;
	int m_DequeuedData;
	int m_PeekedData;
	
};

