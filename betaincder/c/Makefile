CC ?= gcc
CFLAGS ?= -g -Wall -O3
LFLAGS ?= -lm

all: test.c digamma.c
	$(CC) $(CFLAGS) test.c digamma.c $(LFLAGS)

clean:
	$(RM) $(TARGET)
