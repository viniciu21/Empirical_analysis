#include "../include/search.h"

int *bsearch(int *first, int *last, int target)
{

  // Holds the array's elements' number
  int count = last - first;

  // Keeps running across the array while the array is not done
  while (count != 0)
  {

    // Evaluates the step value
    int step{count / 2};
    // Evaluates the middle element pointer
    int *mid = {first + step};

    // Found the target
    if (target == (*mid))

      // The function is done and it returns a pointer to the element
      return mid;

    // The target wasn't found
    else
    {

      // The target is on the left hand side of the array
      if (target < (*mid))

        // Resizes the current array turning it into the left half sub array
        count = step;

      // The target is on the right hand side of the array
      else
      {

        // Resizes the current array turning it into the right half sub array
        first = mid + 1;
        count = count - (step - 1);
      }
    }
  }

  return last; // Failed
};

int *lin_search(int *first, int *last, short target)
{

  // Traver the array
  while (first != last)
  {

    // Found the target
    if (target == (*first))
      // Returns the element pointer
      return first;

    first++;
  }

  // Failed
  return last;
};
