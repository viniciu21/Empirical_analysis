#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include "../include/search.h"

using namespace std;

int main()
{

	ofstream linearf, binaryf; //Arquivos de saida
	linearf.open("data/linear.txt");
	binaryf.open("data/binary.txt");

	short target{1}; //O que nosso algoritmo vai buscar
	long double bin_values[100], lin_values[100];

	for (int indexI{50}; indexI <= 100000; indexI += 50)
	{

		int *samples = new int[indexI]; //Inicialização do array
		fill_n(samples, indexI, 0);		//Enchendo o array com zeros

		int *begin{samples}; //Ponteiros para o inicio e o fim do array
		int *end{(samples + indexI) - 1};

		long double lin_sum{0}, bin_sum{0}, lin_average, bin_average; //Somatório e medias

		for (int indexJ{0}; indexJ < 100; indexJ++)
		{
			//Tempo de execução da busca linear
			auto start_time = chrono::steady_clock::now();

			lsearch(begin, end, target);

			auto end_time = chrono::steady_clock::now();
			auto difference = end_time - start_time;

			lin_values[indexJ] = chrono::duration<long double, milli>(difference).count();

			//Tempo de execução da busca binária
			start_time = chrono::steady_clock::now();

			bsearch(begin, end, target);

			end_time = chrono::steady_clock::now();
			difference = end_time - start_time;

			bin_values[indexJ] = chrono::duration<long double, milli>(difference).count();
		}
		// Média dos tempos
		for (int indexJ{0}; indexJ < 100; indexJ++)
		{
			lin_sum += lin_values[indexJ];
			bin_sum += bin_values[indexJ];
		}

		lin_average = lin_sum / 100;
		bin_average = bin_sum / 100;

		//Imprimindo as médias nos arquivos de saída
		linearf << indexI << " " << lin_average << endl;
		binaryf << indexI << " " << bin_average << endl;
	}
	//Fechando as instancias arquivos de saida
	linearf.close();
	binaryf.close();

	return 0;
}
