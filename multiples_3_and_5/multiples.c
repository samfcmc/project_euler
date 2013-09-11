/*
 * Multiples of 3 or 5 below 1000
 */

#include <stdio.h>
#include <stdlib.h>

int sum_multiples_below(int* numbers, int size_numbers, int limit) {
	int i, j, sum = 0;

	for(i = 0; i < limit; i++) {
		for(j = 0; j < size_numbers; j++) {
			if( !(i % numbers[j]) ) {
				sum += i;
				break;
			}
		}
	}

	return sum;
}

int main(int argc, char* argv[]) {
	int *numbers, size, i, limit, result;

	if(argc < 3) {
		printf("Usage: multiples n1 n2 ... nn limit\n");
		printf("Argc: %d\n", argc);
		return -1;
	}

	/*Program name + limit = 2*/
	size = argc - 2;

	numbers = (int*) malloc(sizeof(int) * size);

	for(i = 0; i < size; i++) {
		numbers[i] = atoi(argv[i+1]);
	}

	limit = atoi(argv[argc - 1]);

	result = sum_multiples_below(numbers, size, limit);

	printf("Result: %d\n", result);

	return 0;
}