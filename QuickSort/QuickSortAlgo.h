#pragma once
#include <iostream>

class CQuickSortAlgo
{
public:
	CQuickSortAlgo();
	~CQuickSortAlgo();

	void SetArraySize(int _arraySize);
	void SetArrayElements(int _index, int _element);

	void PrintArray();

	void QuickSort(int _first, int _last);
	int SortLastElement(int _first, int _last);
	void Swap(int &_num1, int &_num2);

	void ReverseArray();

private:
	int* m_iArray;
	int* m_iReverseArray;
	int m_iArraySize;
};

