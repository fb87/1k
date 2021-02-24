// # SS.0004
// ---
// * Sum(N): 1/2 + 3/4 + 5/6 + .. + (2N+1)/(2N+2)
//   * N as input
//   * N > 0 && N < 1^6
#include <lib.h>

double calculate(int n) {
	double sum = 0;

	for (int i = 0; i < n; i++) {
		sum += (double)(i*2 + 1)/(i*2 + 2);
	}

	return sum;
}
