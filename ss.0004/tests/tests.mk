CC			:= gcc
CFLAGS		:= -Iinc -Itests
LDFLAGS		:= -lcmocka -lm

RM			:= rm -Rf
MKDIR		:= mkdir -p

bin_dir		:= bin
target		:= ${bin_dir}/ss.0004
srcs		:= src/lib.c \
			   tests/testcases.c

all: prebuild ${target}

prebuild: gentest
	@${MKDIR} ${bin_dir}

gentest:
	@scripts/gen-tests.sh

${target}:
	@${CC} -o $@ ${CFLAGS} ${srcs} ${LDFLAGS}

clean: ${bin_dir}
	@${RM} $< tests/testcases.h

