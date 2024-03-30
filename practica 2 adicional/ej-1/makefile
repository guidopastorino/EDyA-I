TARGET = main

SRCS = main.c ArrayList.c

CC = gcc

CFLAGS = -Wall -Wextra

${TARGET}: ${SRCS}
	@${CC} ${CFLAGS} ${SRCS} -o ${TARGET}

clean:
	@del ${TARGET}.exe

all: ${TARGET}

run: ${TARGET}
	@${TARGET}.exe

.PHONY: clean run