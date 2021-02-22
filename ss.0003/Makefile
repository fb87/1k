CC			:= gcc
CFLAGS		:= -Iinc
LDFLAGS		:= -lcmocka

RM			:= rm -Rf
MKDIR		:= mkdir -p

bin_dir		:= bin
target		:= ${bin_dir}/ss.0003

all: prebuild ${target}

prebuild:
	@${MKDIR} ${bin_dir}

${target}: src/main.c
	@${CC} -o $@ ${CFLAGS} $< ${LDFLAGS}

clean: ${bin_dir}
	@${RM} $<

