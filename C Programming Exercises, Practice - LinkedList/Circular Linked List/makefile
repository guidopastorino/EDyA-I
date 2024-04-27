TARGET = ej-$(NUMERO)

SRCS = ej-$(NUMERO).c CSList_Funcs.c

CC = gcc
CFLAGS = -Wall -Wextra

${TARGET}: ${SRCS}
	@${CC} ${CFLAGS} ${SRCS} -o ${TARGET}

clean:
	@rm -f ${TARGET}

all: ${TARGET}

run: ${TARGET}
	@./${TARGET}

.PHONY: clean run

# ---

# Run program
# ex. to execute ej-1.c: make run NUMERO=01