#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "testcases.h"

int main(int argc, char *argv[]) {
	DECL_TESTSUITE(_testsuite);
	return cmocka_run_group_tests(_testsuite, NULL, NULL);
}
