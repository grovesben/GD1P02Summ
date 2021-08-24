#pragma once

enum ERROR {
	STACK_IS_EMPTY = -1
};

class CNode
{
private:
	int m_Data;
	CNode* m_NextNode;

public:
	CNode();
	~CNode();

	void SetData(int _iData);
	int GetData() const;

	CNode* GetNextNode();
	void SetNextNode(CNode* _pNextNode);
};

