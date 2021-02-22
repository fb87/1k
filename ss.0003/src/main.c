// # SS.0003
// ---
// * Sum(N): 1/2 + 2/2 + 3/2 + .. + N/2
//   * N as input
//   * N > 0 && N < 1^6
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

// function to be tested
static float do_sum(int n) {
	float sum = 0;

	for (int i = 1; i <= n; i++)
		sum += (float)i/2;

	return sum;
}

// test function
static void _ut_do_sum(void **state) {
    (void) state;

	// N=1 -> Sum(N)=0.5
	assert_true(do_sum(1) == 0.5);

	// N=2 -> Sum(N)=1/2+2/2 = 0.5 + 1 = 1.5
	assert_true(do_sum(2) == 1.5);

	// N=5 -> Sum(N)=1/2 + 2/2 + 3/2 + 4/2 + 5/2 = 7.5
	assert_true(do_sum(5) == 7.5);

	// N=100 -> Sum(N)=1/2+2/2+...+100/2 = 2525.0
	assert_true(do_sum(100) == 2525.0);
}

int main(int argc, char *argv[]) {
	const struct CMUnitTest _testsuite[] = {
		cmocka_unit_test(_ut_do_sum),
	};
	return cmocka_run_group_tests(_testsuite, NULL, NULL);
}
