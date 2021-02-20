// # SS.0001
// ---
// * Sum(N): 1 + 2 + 3 + .. + N
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
		sum += i;

	return sum;
}

// test function
static void _ut_do_sum(void **state) {
    (void) state;

	// N=1 -> Sum(N)=1
	assert_true(do_sum(1) == 1);

	// N=2 -> Sum(N)=1+2 = 3
	assert_true(do_sum(2) == 3);

	// N=5 -> Sum(N)=1+2+3+4+5 = 15
	assert_true(do_sum(5) == 15);

	// N=100 -> Sum(N)=1+2+...+100 = ???
	assert_false(do_sum(100) == 15);
}

int main(int argc, char *argv[]) {
	const struct CMUnitTest _testsuite[] = {
		cmocka_unit_test(_ut_do_sum),
	};
	return cmocka_run_group_tests(_testsuite, NULL, NULL);
}
