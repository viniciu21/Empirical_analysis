#include <iostream>
#include <chrono>
#include <algorithm> // std::fill_n()
#include <iterator>  //std::begin(), std::end()

#define N 10000000

int main(void)
{
  int *V = new int[N];
  int target{3};
  size_t sz{sizeof(V) / sizeof(V[0])};
  size_t left{0};
  size_t right{sz - 1};
  std::fill_n(V, N, 2);

  std::cout << ">>> STARTING computation that needs timing <<<\n";
  auto start = std::chrono::steady_clock::now();
  //================================================================================

  // Put the code that needs timing here
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
