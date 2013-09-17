/*
 * Find the largest palindrome which is the product of two numbers
 * with n digits
 */

#include <stdio.h>

#define max(a, b) (((a) > (b)) ? a : b)

int reverse(int n) {
	int digit, result = 0;

	while(n > 0) {
		digit = n % 10;
		result = result * 10 + digit;
		n /= 10;
	}

	return result;
}

inline int is_palindrome(int n) {
	int inv = reverse(n);

	return inv == n;
}

int largest_number_with_n_digits(int n_digits) {
	int result = 0;

	for(; n_digits > 0; n_digits--) {
		result = result * 10 + 9;
	}

	return result;
}

int largest_product(int n_digits) {
	int n1, n2, product = 0, i, largest, max = 0;

	largest = largest_number_with_n_digits(n_digits);

	for(n1 = largest; n1 > 0; n1--) {
		for(n2 = n1; n2 > 0; n2--) {
			product = n1 * n2;
			if(is_palindrome(product)) {
				max = max(max, product);
				printf("Palindrome found: %d x %d = %d\n", n1, n2, product);
				break;
			}
		}
	}

	return max;
}

int main(int argc, char *argv[]) {
	int number, result;

	if(argc < 2) {
		printf("Usage: palindrome number\n");
		return -1;
	}

	number = atoi(argv[1]);

	result = largest_product(number);

	printf("Result: %d\n", result);

	return 0;
}