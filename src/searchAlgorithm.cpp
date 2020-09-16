#include "../include/search.h"

int *bsearch(int *first, int *last, short target){

	int count = last - first;	// Holds the array's elements' number

	while (count != 0){	// Keeps running across the array while the array is not done

		int step{count / 2};	// Evaluates the step value
		int *mid = first + step;	// Evaluates the middle element pointer
		
		if (target == (*mid))	// Found the target
			return mid; // The function is done and it returns a pointer to the element

		else{	// The target wasn't found
			if (target < (*mid))	// The target is on the left hand side of the array
				count = step;	// Resizes the current array turning it into the left half sub array

			else{	// The target is on the right hand side of the array
				first = mid + 1;	// Resizes the current array turning it into the right half sub array
				count = count - step - 1;	// Updates the number of elements of the array
			}
		}
	}
	return last; // Failed
};

int *lsearch(int *first, int *last, short target){

	while (first != last){	// Travel the array
		if (target == (*first))	// Found the target
			return first;	// Returns the element pointer

		first++;
	}

	return last;	// Failed
};
