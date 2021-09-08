#pragma once
#include "QuickSortAlgo.h"
#include <vector>

class CQuickSortManager
{
public:
	CQuickSortManager();
	~CQuickSortManager();

	void Run();
	int InputOrderCheck();
	int InputSizeCheck();
	int InputElementsCheck();

private:
	CQuickSortAlgo* m_oQuickSortAlgo;
	bool m_bOrder;
	int m_iInput;
	int m_iSize;
	int m_iElement;
	std::vector<int> m_viElements;
};

