#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "IAlgorithm.h"
#include <vector>
#include <string>

namespace algo
{
	class BinarySearch : public IAlgorithm<BinarySearch>
	{
	public:
		BinarySearch();
		~BinarySearch();

		void printProblemStatement() override;
		void input() override;
		void process()  override;
		void output() override;

	private:
		std::vector<int> inputData;
		int searchElement = 0;
		int positionOfSearchElement = -1;
	};
} // namespace algo

#endif // BINARYSEARCH_H

