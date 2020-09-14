#include <iostream>
#include <chrono>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "../include/search.h"

// using std::cout;
// using std::ofstream;
// using std::fill_n;
using namespace std;

int main()
{
	srand((unsigned)time(0));

	short target{6};
	// int V[5] = {1, 2, 3, 4, 5};
	// int *begin = std::begin(V);
	// int *end = std::end(V);
	// int *result = bsearch(begin, end, target);
	// cout << *result << "\n";

	ofstream tempo_blinear, tempo_bbinaria;
	tempo_blinear.open("saida_linear.txt");
	tempo_bbinaria.open("saida_binaria.txt");

	for (int indexI{50}; indexI <= 10000; indexI += 50)
	{
		int *amostra = new int[indexI];
		fill_n(amostra, indexI, 0);
		int *begin{amostra};
		int *end{(amostra + indexI) - 1};

		for (int indexJ{0}; indexJ < 100; indexJ++)
		{
			auto comeco = chrono::steady_clock::now();

			lin_search(begin, end, target);

			auto fim = chrono::steady_clock::now();
			auto diferenca = fim - comeco;

			tempo_blinear << indexI << " " << chrono::duration<double, milli>(diferenca).count() << endl;
		};
	};

	tempo_blinear.close();
	tempo_bbinaria.close();

	return 0;
}
