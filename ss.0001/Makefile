CC			:= gcc
CFLAGS		:= -Iinc
LDFLAGS		:= -lcmocka

RM			:= rm
MKDIR		:= mkdir

target		:= bin/ss.0001

all: prebuild ${target}

prebuild:
	@${MKDIR} -p bin

${target}: src/main.c
	@${CC} -o $@ ${CFLAGS} $< ${LDFLAGS}

clean: ${target}
	@${RM} -f $<

