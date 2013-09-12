/*
 * Get the largest prime factor
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ( ((a) > (b)) ? a : b )

/*
 * is_prime: Check if n is prime or not
 */

int is_prime(unsigned long long int n) {
	long long int i;

	for(i = n - 1; i > 1; i--) {
		if( !(n % i) ) {
			return 0;
		}
	}

	return 1;
}

unsigned long long int largest_prime_factor(unsigned long long int n) {
	long long int current_factor = 2, max_factor = 0;

	while(n > 1) {
		if( !(n % current_factor) && is_prime(current_factor) ) {
			n /= current_factor;
			max_factor = max(current_factor, max_factor);
		}
		else {
			current_factor++;
		}
	}

	return max_factor;
}

int main(int argc, char *argv[]) {
	unsigned long long int result, number;

	if(argc < 2) {
		printf("Usage: prime number\n");
		return -1;
	}

	number = strtoull(argv[1], (char**) NULL, 10);

	result = largest_prime_factor(number);

	printf("Result: %lld\n", result);

	return 0;
}

