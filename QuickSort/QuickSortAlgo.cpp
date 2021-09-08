#include "QuickSortAlgo.h"

CQuickSortAlgo::CQuickSortAlgo()
{
	m_iArray = nullptr;
	m_iReverseArray = nullptr;
	m_iArraySize = 0;
}

CQuickSortAlgo::~CQuickSortAlgo()
{
	delete[] m_iArray;
	delete[] m_iReverseArray;
}

void CQuickSortAlgo::SetArraySize(int _arraySize)
{
	m_iArray = new int[_arraySize];
	m_iArraySize = _arraySize;
}

void CQuickSortAlgo::SetArrayElements(int _index, int _element)
{
	m_iArray[_index] = _element;
}

void CQuickSortAlgo::PrintArray()
{
	for (int i = 0; i < m_iArraySize; ++i)
	{
		std::cout << m_iArray[i] << " ";
	}
}

void CQuickSortAlgo::QuickSort(int _first, int _last)
{
	if (_first < _last) // conditional blocks invalid recurse calls.
	{
		int sortedLastElement = SortLastElement(_first, _last); // puts the last element in the array in its correct spot,
																// with everything to the left and right, lesser/greater respectively.
		QuickSort(_first, sortedLastElement - 1);		// recurse with all elements above and below the element in its correct position.
		QuickSort(sortedLastElement + 1, _last);
	}
}

int CQuickSortAlgo::SortLastElement(int _first, int _last)
{
	int pivot = m_iArray[_last];	// sets the last element as the pivot point.
	int upCounter = (_first - 1);	// set to -1 because it gets iterated to 0 first time its called to point at first element.

	for (int i = _first; i <= _last - 1; i++)
	{
		if (m_iArray[i] <= pivot) // everything less than pivot gets put at start of array.
		{
			upCounter++; 
			Swap(m_iArray[i], m_iArray[upCounter]);
		}
	}
	Swap(m_iArray[upCounter + 1], m_iArray[_last]);	// pivot put to the right of everything less than it. in its right place.
	
	return (upCounter + 1);// returns the index of the element in its absolute right place.
}

void CQuickSortAlgo::Swap(int &_num1, int &_num2)
{
	int temp = _num1;
	_num1 = _num2;
	_num2 = temp;
}

void CQuickSortAlgo::ReverseArray()
{
	m_iReverseArray = new int[m_iArraySize];
	int j = m_iArraySize - 1;

	for (int i = 0; i < m_iArraySize; ++i)
	{
		m_iReverseArray[j] = m_iArray[i];
		--j;
	}

	for (int i = 0; i < m_iArraySize; ++i)
	{
		m_iArray[i] = m_iReverseArray[i];
	}
}
