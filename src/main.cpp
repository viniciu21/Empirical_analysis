#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include "../include/search.h"

using namespace std;

int main()
{

	ofstream linearf, binaryf;
	linearf.open("data/linear.txt");
	binaryf.open("data/binary.txt");

	short target{1};
	long double bin_values[100], lin_values[100];

	for (int indexI{50}; indexI <= 100000; indexI += 50)
	{

		int *samples = new int[indexI];
		fill_n(samples, indexI, 0);

		int *begin{samples};
		int *end{(samples + indexI) - 1};

		long double lin_sum{0}, bin_sum{0}, lin_average, bin_average;

		for (int indexJ{0}; indexJ < 100; indexJ++)
		{

			auto start_time = chrono::steady_clock::now();

			lsearch(begin, end, target);

			auto end_time = chrono::steady_clock::now();
			auto difference = end_time - start_time;

			lin_values[indexJ] = chrono::duration<long double, milli>(difference).count();

			start_time = chrono::steady_clock::now();

			bsearch(begin, end, target);

			end_time = chrono::steady_clock::now();
			difference = end_time - start_time;

			bin_values[indexJ] = chrono::duration<long double, milli>(difference).count();
		}

		for (int indexJ{0}; indexJ < 100; indexJ++)
		{
			lin_sum += lin_values[indexJ];
			bin_sum += bin_values[indexJ];
		}

		lin_average = lin_sum / 100;
		bin_average = bin_sum / 100;

		linearf << indexI << " " << lin_average << endl;
		binaryf << indexI << " " << bin_average << endl;
	}

	linearf.close();
	binaryf.close();

	return 0;
}
