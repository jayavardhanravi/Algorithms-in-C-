#include "BinarySearch.h"

algo::BinarySearch::BinarySearch()
{
}

algo::BinarySearch::~BinarySearch()
{
}

void algo::BinarySearch::printProblemStatement()
{
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Problem: Binary Search" << std::endl;
	std::cout << "Notes: \nBinary search is used to find elements in a sorted list"
		<< "\n- Like a dictionary or search name on facebook etc."
		<< "\n- Binary search returns the position of the element we are searching in the list"
		<< "\n- If the element is not found then returns the NULL value"
		<< std::endl;
}

void algo::BinarySearch::input()
{
	// assigning input data
	inputData = { 12, 18, 23, 25, 29, 32, 35, 40, 58, 66 };
	searchElement = 29;

	// Printing the input to console
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Input: list of integers" << std::endl;
	for(int item: inputData)
		std::cout << item << " ";
	std::cout << std::endl;
	std::cout << "Search Element: " << searchElement << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}

void algo::BinarySearch::process()
{
	processTimer<nano>(TIMER::START);
	// Core Algorithm
	int startCursor = 0, endCursor = inputData.size() - 1;
	while (startCursor <= endCursor)
	{
		unsigned int midPosition = unsigned int((endCursor - startCursor) / 2) + startCursor;
		if (searchElement == inputData[midPosition])
		{
			positionOfSearchElement = midPosition;
			break;
		}
		else if (searchElement > inputData[midPosition])
		{
			startCursor = midPosition + 1;
		}
		else if (searchElement < inputData[midPosition])
		{
			endCursor = midPosition - 1;
		}
	}
	processTimer<nano>(TIMER::END);
	std::cout << "Processing Time: " << processTimer<nano>(TIMER::PRINT) << " ns" << std::endl;
}

void algo::BinarySearch::output()
{
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Output:" 
		<< "\n- Search Element: " << searchElement
		<< "\n- Position of SearchElement: " << positionOfSearchElement
		<< std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}
