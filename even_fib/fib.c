/*
 * Even fibonnaci terms
 */

 #include <stdio.h>

 int even_fib_sum(int limit) {
 	int terms[] = {1, 2};
 	int sum = terms[1];
 	int result = 3;
 	int *next;

 	printf("Terms: %d %d ", terms[0], terms[1]);

 	while(result < limit) {
 		next = terms + 1;
 		result = *terms + *next;
 		*terms = *next;
 		*next = result;

 		/* If result is even */
 		if(!(result & 1)) {
 			sum += result;
 		}

 		printf("%d ", result);
 	}

 	printf("\n");

 	return sum;
 }

 int main(int argc, char* argv[]) {
 	int limit;

 	if(argc != 2) {
 		printf("Usage: fib limit\n");
 		return -1;
 	}

 	limit = atoi(argv[1]);

 	int result = even_fib_sum(limit);

 	printf("Result: %d\n", result);

 	return 0;
 }