#include <iostream>
#include <chrono>
#include <algorithm> // std::fill_n()
#include <iterator>  //std::begin(), std::end()

#define N 10000000

int *bsearchponteir(int *first, int *last, int target)
{
    // std::cout << *first << "  " << *(last-1) <<"\n";
    int *primeirolast = last - 1;
    size_t size;
    int *mid;
    while (first < last)
    { //count != 0
        size = last - first;
        //count = last-first (numero de elementos )
        //std::cout<< size << "\n";
        mid = first + (size / 2);
        //stop = count/2
        // mid = first + stop
        std::cout << *mid << "\n";
        if (*mid == target)
        {
            return mid;
        }
        else if (*mid > target)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return primeirolast;
}

int bsearch_i(int *A, size_t l, size_t r, int target)
{

    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (A[mid] == target)
        {
            return mid;
        }
        else if (A[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1; // STUB
}

int main(void)
{
    // [1]=== Criar os dados.
    srand((unsigned)time(0));
    int *V = new int[N];
    int target{3}; // worst case
    size_t sz{sizeof(V) / sizeof(V[0])};
    size_t left{0};
    size_t right{sz - 1};
    std::fill_n(V, N, 2); //Filling in V with N number "2".
    // [2]=== Medir e exibir o tempo da busca binária recursiva.
    // [3]=== Medir e exibir o tempo da busca binária iterativa.
    // [4]=== Liberar a memoria;
    std::cout << ">>> STARTING computation that needs timing <<<\n";
    auto start = std::chrono::steady_clock::now();
    //================================================================================

    // Put the code that needs timing here
    bsearch_i(V, left, right, target);
    //================================================================================
    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";

    //Store the time difference between start and end
    // auto diff = end - start;
    std::chrono::duration<double> diff = end - start;

    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration<double, std::milli>(diff).count()
              << " ms" << std::endl;

    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration<double, std::nano>(diff).count()
              << " ns" << std::endl;

    // Seconds
    auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;

    return EXIT_SUCCESS;
}
