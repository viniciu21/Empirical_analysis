#include <iostream>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>
#include "../include/search.h"

using std::cout;
using std::vector;

int main()
{
	srand((unsigned)time(0));

	vector<int> vetor;

	for (int indexI{50}; indexI <= 10000; indexI += 50)
	{
		for (int indexJ{0}; indexJ < 100; indexJ++)
		{
			for (int indexX{indexI - 50}; indexX <= indexI; indexX++)
			{
				vetor.push_back(rand() % indexI);
			};
		}
	};

	for (auto &&i : vetor)
	{
		cout << "Index: " << i << "\n";
	}

	return 0;
}
