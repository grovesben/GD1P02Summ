#include "QuickSortManager.h"

CQuickSortManager::CQuickSortManager()
{
	m_oQuickSortAlgo = new CQuickSortAlgo;
	m_bOrder = 0;
	m_iSize = 0;
	m_iElement = 0;
	m_iInput = 1337;
}

CQuickSortManager::~CQuickSortManager()
{
	m_oQuickSortAlgo = nullptr;
}

void CQuickSortManager::Run()
{
	std::cout << "Enter order: ";
	m_iInput = InputOrderCheck(); // checks input
	if (m_iInput == 1337) // exits program if bad input
	{
		return;
	}

	m_iInput == 0 ? m_bOrder = false : m_bOrder = true; // set bool for order

	std::cout << "Enter size of array: ";
	m_iSize = InputSizeCheck(); // checks input
	if (m_iSize == -1337) // exits program if bad input
	{
		return;
	}
	m_oQuickSortAlgo->SetArraySize(m_iSize);

	std::cout << "Enter elements: ";
	m_iInput = InputElementsCheck(); // checks input
	if (m_iInput == 1337) // exits program if bad input
	{
		return;
	}

	for (int i = 0; i < m_iSize; ++i)
	{
		m_oQuickSortAlgo->SetArrayElements(i, m_viElements[i]);
	}

	m_oQuickSortAlgo->QuickSort(0, m_iSize - 1);

	if (m_bOrder)
	{
		m_oQuickSortAlgo->ReverseArray();
	}
	std::cout << "Sorted array: ";
	m_oQuickSortAlgo->PrintArray();
	std::cout << std::endl;

	return;
}

int CQuickSortManager::InputOrderCheck()
{
	if (std::cin >> m_iInput)
	{
		if ((m_iInput == 0 || m_iInput == 1))
		{
			return m_iInput;
		}
	}

	system("CLS");
	std::cout << "Input must be 0 or 1. Did you read the readme ? \n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 1337;
}

int CQuickSortManager::InputSizeCheck()
{
	if (std::cin >> m_iInput)
	{
		if (m_iInput < 0)
		{
			system("CLS");
			std::cout << "Size must be a positive integer. You ok bro?";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return -1337;
		}
		if (m_iInput == 0)
		{
			system("CLS");
			std::cout << "There is nothing to sort. Why are you wasting my time?";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return -1337;
		}
		return m_iInput;
	}
	system("CLS");
	std::cout << "More bad input.. Its gotta be a positive integer. Why are you trying to break me? Who hurt you?\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return -1337;
}

int CQuickSortManager::InputElementsCheck()
{
	while (true)
	{
		std::cin >> m_iInput;
		if (std::cin.fail())
		{
			system("CLS");
			std::cout << "Input bad... thats what she said. \nBut seriously, please input as many integers as the size you input, seperated by a space. Thanks.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 1337;
		}
		else
		{
			m_viElements.push_back(m_iInput);
			if (std::cin.peek() == '\n')
			{
				if (m_viElements.size() != m_iSize)
				{
					system("CLS");
					std::cout << "Size DOES matter.";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return 1337;
				}
				return 0;
			}
		}
	}

}


