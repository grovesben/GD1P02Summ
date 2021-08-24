#include "Node.h"

CNode::CNode() 
{
	m_Data = ERROR::STACK_IS_EMPTY;
	m_NextNode = nullptr;
}

CNode::~CNode() 
{
}

void CNode::SetData(int _iData) 
{
	this->m_Data = _iData;
}

int CNode::GetData() const 
{
	return this->m_Data;
}

CNode* CNode::GetNextNode() 
{
	return m_NextNode;
}

void CNode::SetNextNode(CNode* _pNextNode) 
{
	this->m_NextNode = _pNextNode;
}
