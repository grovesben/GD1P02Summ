#include "Deque.h"


CDeque::CDeque() 
{
	m_Head = nullptr;
}

CDeque::~CDeque() 
{
}

void CDeque::Enqueue_Front(int _iData) 
{
	CNode* temp = m_Head;
	CNode* node = new CNode;
	node->SetData(_iData);
	m_Head = node;
	node->SetNextNode(temp);

}

void CDeque::Enqueue_Back(int _iData) 
{
	CNode* temp = m_Head;
	CNode* tempPrevious = nullptr;
	while (temp != nullptr)
	{
		tempPrevious = temp;
		temp = temp->GetNextNode();
	}
	CNode* node = new CNode;
	node->SetNextNode(nullptr);
	node->SetData(_iData);
	if (tempPrevious != nullptr) 
	{
		tempPrevious->SetNextNode(node);
	}
	else 
	{
		m_Head = node;
	}
}

bool CDeque::Dequeue_Front(int& _riData) 
{
	bool flag = true;
	if (m_Head == nullptr) 
	{
		flag = false;
	}
	else {
		_riData = m_Head->GetData();
		CNode* temp = m_Head;
		m_Head = m_Head->GetNextNode();
		delete temp;
	}
	return flag;
}

bool CDeque::Dequeue_Back(int& _riData) 
{
	bool flag = true;
	if (m_Head == nullptr) 
	{
		flag = false;
	}
	else {
		CNode* temp = m_Head;
		CNode* tempPrevious = nullptr;
		CNode* tempBeforePrevious = nullptr;
		while (temp != nullptr)
		{
			tempBeforePrevious = tempPrevious;
			tempPrevious = temp;
			temp = temp->GetNextNode();
		}
		_riData = tempPrevious->GetData();
		if (tempBeforePrevious != nullptr) 
		{
			tempBeforePrevious->SetNextNode(nullptr);
		}
		if (tempPrevious == m_Head) 
		{
			m_Head = nullptr;
		}
		delete tempPrevious;

	}
	return flag;
}

bool CDeque::Peek_Front(int& _riData) 
{
	bool flag = true;
	if (m_Head == nullptr) 
	{
		flag = false;
	}
	else {
		_riData = m_Head->GetData();
	}
	return flag;
}

bool CDeque::Peek_Back(int& _riData) 
{
	bool flag = true;
	if (m_Head == nullptr) 
	{
		flag = false;
	}
	else {
		CNode* temp = m_Head;
		CNode* tempPrevious = nullptr;
		while (temp != nullptr) 
		{
			tempPrevious = temp;
			temp = temp->GetNextNode();
		}
		_riData = tempPrevious->GetData();
	}
	return flag;
}

bool CDeque::IsEmpty() 
{
	return (m_Head == nullptr);
}

void CDeque::Display() {
	if (m_Head == nullptr) 
	{
		std::cout << "Deque is empty\n\n";
	}
	else {
		std::cout << "Deque = ";
		CNode* temp = m_Head;
		while (temp != nullptr) 
		{
			std::cout << temp->GetData() << " ";
			temp = temp->GetNextNode();
		}
		std::cout << std::endl << std::endl;
	}
}

void CDeque::TestHarness() 
{
	std::cout << "Creating Deque.\n";
	CDeque* deque = new CDeque;

	std::cout << "Enqueue_Back 1,2,3: ";
	deque->Enqueue_Back(1);
	deque->Enqueue_Back(2);
	deque->Enqueue_Back(3);
	deque->Display();

	std::cout << "Dequeue_Front: ";
	int dequeuedData = ERROR::STACK_IS_EMPTY;
	deque->Dequeue_Front(dequeuedData);
	deque->Display();
	std::cout << "Dequeued data: " << dequeuedData;
	std::cout << std::endl;

	std::cout << "Peek_Front: ";
	int peekedData = ERROR::STACK_IS_EMPTY;
	deque->Peek_Front(peekedData);
	deque->Display();
	std::cout << "Peeked data: " << peekedData;
	std::cout << std::endl;

	std::cout << "Enqueue_Front 10,11,12: ";
	deque->Enqueue_Front(10);
	deque->Enqueue_Front(11);
	deque->Enqueue_Front(12);
	deque->Display();

	std::cout << "Dequeue_Back: ";
	dequeuedData = ERROR::STACK_IS_EMPTY;
	deque->Dequeue_Back(dequeuedData);
	deque->Display();
	std::cout << "Dequeued data: " << dequeuedData;
	std::cout << std::endl;

	std::cout << "Peek_Back: ";
	peekedData = ERROR::STACK_IS_EMPTY;
	deque->Peek_Back(peekedData);
	deque->Display();
	std::cout << "Peeked data: " << peekedData;
	std::cout << std::endl;

	std::cout << "Dequeueing all nodes.\n";
	deque->Dequeue_Back(dequeuedData);
	deque->Dequeue_Back(dequeuedData);
	deque->Dequeue_Back(dequeuedData);
	deque->Dequeue_Front(dequeuedData);


	std::cout << "Final Deque: ";
	deque->Display();

}
