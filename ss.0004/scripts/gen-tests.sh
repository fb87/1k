#!/usr/bin/env bash

# set -x

function _ {
	# (2N+1)/(2N+2)
	echo -n "$((2*${1}+1))/$((2*${1}+2))"
}

function __ {
	_arg1=${1}
	_expr="$(_ 0)"

	for i in $(seq 1 $((_arg1-1))); do
		_expr="${_expr} + $(_ ${i})"
	done

	echo -en "\t// ${_expr}"

	_res=$(echo "scale=8; ${_expr}" | bc)
	echo -e " = ${_res}\n\tassert_true(_expected(calculate(${_arg1}), (double)${_res}));"
}

cat <<-EOF > tests/testcases.h
#ifndef __TESTCASES_H__
#define __TESTCASES_H__

// GENERATED CODE - DONNOT MODIFY

#include <math.h>
#include <lib.h>

static inline int _expected(double x, double y) {
	return !!(fabs(x - y) <= (0.0000001 * fabs(x)));
}

$(
_tc=1
for i in 1 2 5 10 27 50 97 100; do
echo "static void _ut_testcase_${_tc}(void **state) {"
	__ ${i}
echo -e "}\n"
	_tc=$((_tc+1))
done

echo "#define DECL_TESTSUITE(x) const struct CMUnitTest x[] = {\\"
for i in $(seq 1 $((_tc-1))); do
	echo -e "\tcmocka_unit_test(_ut_testcase_${i}),\\"
done
echo "};"
)
#endif // __TESTCASES_H__
EOF

