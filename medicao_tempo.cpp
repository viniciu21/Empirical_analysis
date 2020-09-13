#include <cstdlib>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
int main()
{

  int lista[] = {5, 8, 10, 11, 18};
  int amostras[1000000];
  //preparação
  for (int i = 0; i < 1000000; i++)
  {
    amostras[i] = rand() % 20;
    //cout<<amostras[i]<<endl;
  }
  int num;
  int i;
  int aux = 0;
  //cin>>num;

  clock_t begin = clock();
  for (int i = 0; i < 1000000; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (lista[j] == amostras[i])
      {
        break;
      }
    }
  }
  clock_t end = clock();
  double total = double(end - begin) / CLOCKS_PER_SEC;

  cout << total << endl;
}
