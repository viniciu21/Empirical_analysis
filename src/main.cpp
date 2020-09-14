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

	short target{1};
	int *resultado;
	ofstream tempo_blinear, tempo_bbinaria;
	tempo_blinear.open("saida_linear");
	tempo_bbinaria.open("saida_binaria");

	for (int indexI{50}; indexI <= 10000; indexI += 50)
	{
		int* amostra = new int[indexI];
		fill_n(amostra, indexI, 0);
		int *begin = std::begin(amostra), *end = std::end(amostra);

		for (int indexJ{0}; indexJ < 100; indexJ++)
		{
			auto comeco = chrono::steady_clock::now();

			resultado = lin_search(begin, end, target);
			
			auto fim = chrono::steady_clock::now();
			auto diferenca = fim - comeco;
			
			tempo_blinear << indexI << " " << chrono::duration<double, milli>(diferenca).count() << endl;
		}
	};

	tempo_blinear.close();
	tempo_bbinaria.close();

	return 0;
}
