#pragma once

#include "Node.h"
#include <iostream>

class CDeque
{
private:
	CNode* m_Head;

public:
	CDeque();
	~CDeque();

	void Enqueue_Front(int _iData);
	void Enqueue_Back(int _iData);
	bool Dequeue_Front(int& _riData);
	bool Dequeue_Back(int& _riData);
	bool Peek_Front(int& _riData);
	bool Peek_Back(int& _riData);
	bool IsEmpty();
	void Display();

	static void TestHarness();
};

