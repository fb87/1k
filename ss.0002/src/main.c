// # SS.0002
// ---
// * Sum(N): 1^2 + 2^2 + 3^2 + .. + N^2
//   * N as input
//   * N > 0 && N < 1^6
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

// function to be tested
static long do_sum(int n) {
	long sum = 0;

	for (int i = 1; i <= n; i++)
		sum += i*i;

	return sum;
}

// test function
static void _ut_do_sum(void **state) {
    (void) state;

	// N=1 -> Sum(N)=1
	assert_true(do_sum(1) == 1);

	// N=2 -> Sum(N)=1^2+2^2 = 1 + 4 = 5
	assert_true(do_sum(2) == 5);

	// N=5 -> Sum(N)=1^2 + 2^2 + 3^2 + 4^2 + 5^2 = 55
	assert_true(do_sum(5) == 55);

	// N=100 -> Sum(N)=1^2+2^2+...+100^2 = 338350
	assert_true(do_sum(100) == 338350);
}

int main(int argc, char *argv[]) {
	const struct CMUnitTest _testsuite[] = {
		cmocka_unit_test(_ut_do_sum),
	};
	return cmocka_run_group_tests(_testsuite, NULL, NULL);
}
