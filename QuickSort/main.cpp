#include "QuickSortManager.h"
#include <conio.h>
#include <stdlib.h>

int main()
{
	CQuickSortManager QuickSortManager;
	QuickSortManager.Run();
	

	std::cout << "\nPress any key to exit.\n"; // soft exit
	char cTemp;
	cTemp = _getch();

	return cTemp;
}